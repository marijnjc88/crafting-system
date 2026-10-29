#pragma once

#include "CoreMinimal.h"
#include "CraftingResourceInput.generated.h"

class UCraftingResource;

USTRUCT(BlueprintType)
struct PROCEDURALCRAFTING_API FCraftingResourceInput
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Crafting")
	TObjectPtr<UCraftingResource> Resource = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Crafting")
	int Amount = 1;
};
