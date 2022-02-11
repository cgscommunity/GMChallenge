
#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "GameplayTagAssetInterface.h"
#include "GMCChair.generated.h"

UCLASS()
class GMCHALLENGE_API AGMCChair 
	: public AStaticMeshActor
	, public IGameplayTagAssetInterface
{
	GENERATED_BODY()
	
public:
		// IGameplayTagAssetInterface
		void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;
		// IGameplayTagAssetInterface

		UFUNCTION(BlueprintCallable, Category = GameplayTags)
		void ResetGameplayTags() { GameplayTagContainer.Reset(); }
protected:
	UPROPERTY(EditAnywhere, Category = GameplayTags)
	FGameplayTagContainer GameplayTagContainer;
};
