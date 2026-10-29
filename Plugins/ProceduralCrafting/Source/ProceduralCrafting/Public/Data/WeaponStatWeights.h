#pragma once

#include "CoreMinimal.h"
#include "ResourceStat.h"
#include "WeaponStatWeights.generated.h"

USTRUCT(BlueprintType)
struct PROCEDURALCRAFTING_API FWeaponStatInfluence
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon Stats", meta = (ClampMin = "0.0", UIMin = "0.0"))
	float Weight = 1.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon Stats")
	bool bInverse = false;
};

USTRUCT(BlueprintType)
struct PROCEDURALCRAFTING_API FWeaponStatWeights
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon Stats")
	TMap<EResourceStat, FWeaponStatInfluence>Weights;
};
