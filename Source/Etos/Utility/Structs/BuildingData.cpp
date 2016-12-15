// © 2016 - 2017 Daniel Bortfeld

#include "Etos.h"
#include "BuildingData.h"
#include "PredefinedBuildingData.h"

FBuildingData::FBuildingData(const FPredefinedBuildingData & predefData)
{
	BuildCost = predefData.BuildCost;
	BuildingIcon = predefData.BuildingIcon;
	MaxStoredResources = predefData.MaxStoredResources;
	Name = predefData.Name;
	NeededResource1 = FResource(predefData.NeededResource1);
	NeededResource2 = FResource(predefData.NeededResource2);
	ProducedResource = FResource(predefData.ProducedResource);
	ProductionTime = predefData.ProductionTime;
	Radius = predefData.Radius;
	Upkeep = predefData.Upkeep;
}
