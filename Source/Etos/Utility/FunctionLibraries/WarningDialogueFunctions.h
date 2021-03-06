// © 2016 - 2017 Daniel Bortfeld

#pragma once

#include "Etos/Utility/InOut.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WarningDialogueFunctions.generated.h"

#define IMPLEMENT_FUNCTION_PTR_RESOLVER_ReturnVal(ReturnValueType, /*FunctionParams*/ ...) \
template< class ObjectClass> \
class TFunctionPtrResolver \
{ \
public: \
 \
	typedef ReturnValueType(ObjectClass::*FunctionPtr)(__VA_ARGS__); \
}; \

#define IMPLEMENT_FUNCTION_PTR_RESOLVER(/*FunctionParams*/ ...) IMPLEMENT_FUNCTION_PTR_RESOLVER_ReturnVal(void, __VA_ARGS__)

/**
 *
 */
UCLASS()
class ETOS_API UWarningDialogueFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	DECLARE_DYNAMIC_DELEGATE(FOnButtonReleased);
	IMPLEMENT_FUNCTION_PTR_RESOLVER();

public:

	UFUNCTION(BlueprintCallable, Category = "WarningDialogue", meta = (DisplayName = "Show Warning Dialogue", WorldContext = "WorldContextObject", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", UnsafeDuringActorConstruction = "true"))
		static void BP_ShowWarningDialogue(UObject* WorldContextObject, TSubclassOf<UWarning> WarningWidget, FOnButtonReleased const& OnReleasedYes, FOnButtonReleased const& OnReleasedNo);

	template <typename PositiveReceiverClass, typename NegativeReceiverClass>
	static void __Internal_ShowWarningDialogue(UObject* WorldContextObject, TSubclassOf<UWarning> in WarningWidget, PositiveReceiverClass* PositiveCallbackReceiver, typename TFunctionPtrResolver<PositiveReceiverClass>::FunctionPtr in OnReleasedYes, FName in OnReleasedYes_FunctionName, NegativeReceiverClass* NegativeCallbackReceiver, typename TFunctionPtrResolver<NegativeReceiverClass>::FunctionPtr in OnReleasedNo, FName in OnReleasedNo_FunctionName);

#define ShowWarningDialogue(PositiveReceiverClass, NegativeReceiverClass, WorldContextObject, WarningWidget, PositiveCallbackReceiver, OnReleasedYes, NegativeCallbackReceiver, OnReleasedNo) \
	__Internal_ShowWarningDialogue<PositiveReceiverClass, NegativeReceiverClass>(WorldContextObject, WarningWidget, \
	PositiveCallbackReceiver, OnReleasedYes, \
	OnReleasedYes != nullptr ? STATIC_FUNCTION_FNAME(TEXT(#OnReleasedYes)) : FName(), \
	NegativeCallbackReceiver, OnReleasedNo, \
	OnReleasedNo != nullptr ? STATIC_FUNCTION_FNAME(TEXT(#OnReleasedNo)) : FName());

};

typedef UWarningDialogueFunctions FWarning;
