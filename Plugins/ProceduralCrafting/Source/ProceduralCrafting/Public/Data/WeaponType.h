#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WeaponStats.h"
#include "WeaponStatWeights.h"
#include "WeaponType.generated.h"

UCLASS(BlueprintType)
class PROCEDURALCRAFTING_API UWeaponType : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
	FText Name;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
	FWeaponStats BaseStats;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
	FWeaponStatWeights DamageWeights;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
	FWeaponStatWeights DurabilityWeights;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
	FWeaponStatWeights AttackSpeedWeights;
};
