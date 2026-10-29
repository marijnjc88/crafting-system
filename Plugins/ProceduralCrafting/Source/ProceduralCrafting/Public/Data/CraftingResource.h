#pragma once

#include "CoreMinimal.h"
#include "ResourceStats.h"
#include "CraftingResource.generated.h"

UCLASS(BlueprintType)
class PROCEDURALCRAFTING_API UCraftingResource : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource")
	FText Name;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Resource")
	FResourceStats Stats;
	
	UFUNCTION(BlueprintPure, Category = "Resource")
	float GetStat(const EResourceStat Stat) const
	{
		return Stats.GetStat(Stat);
	}
};
