#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ProceduralCraftingSettings.generated.h"

UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Procedural Crafting"))
class PROCEDURALCRAFTING_API UProceduralCraftingSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	virtual FName GetCategoryName() const override
	{
		return TEXT("Plugins");
	}
	
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Weapon Generation", meta = (ClampMin = "0.001", UIMin = "1.0"))
	float NeutralScore = 50.0f;
	
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Weapon Generation", meta = (ClampMin = "0.0"))
	float DamageOffset = 1.0f;
	
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Weapon Generation", meta = (ClampMin = "0.0"))
	float DurabilityOffset = 1.0f;
	
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Weapon Generation", meta = (ClampMin = "0.0"))
	float AttackSpeedOffset = 0.1f;
};