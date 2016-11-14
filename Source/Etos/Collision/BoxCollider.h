// © 2016 - 2017 Daniel Bortfeld

#pragma once // unreal somehow does not generate a generated.h file when using #ifndef

class UBoxCollider;

#include "Components/SceneComponent.h"
#include "BoxCollider.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCollisionDelegate, UBoxCollider*, other);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ETOS_API UBoxCollider : public USceneComponent
{
	GENERATED_BODY()

public:

	UPROPERTY()
		UBoxComponent* Collider;

	UPROPERTY()
		FCollisionDelegate OnTriggerEnter;

	UPROPERTY()
		FCollisionDelegate OnTriggerStay;

	UPROPERTY()
		FCollisionDelegate OnTriggerExit;

private:

	UPROPERTY()
		TArray <UBoxCollider*> collisions;

	UPROPERTY()
		bool bGenerateCollisionEvents;

public:
	// Sets default values for this component's properties
	UBoxCollider();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void BeginDestroy() override;

	void CheckCollision(UBoxCollider* other);

	//void CheckCollision(const UBoxCollider& other);

	bool GetGenerateCollisionEvents();

	void SetGenerateCollisionEvents(bool shouldGenerate);
};
