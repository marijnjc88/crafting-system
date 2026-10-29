#pragma once

#include "CoreMinimal.h"
#include "WeaponStats.generated.h"

USTRUCT(BlueprintType)
struct PROCEDURALCRAFTING_API FWeaponStats
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon Stats")
	float Damage = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon Stats")
	float Durability = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon Stats")
	float AttackSpeed = 0.0f;
};
