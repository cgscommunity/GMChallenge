// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GameFramework/HUD.h"
#include "GMCGameMode.generated.h"

class UGMCHUD;
class UGMCInteractPopUp;

UCLASS()
class GMCHALLENGE_API AGMCGameMode : public AGameMode
{
	GENERATED_BODY()

public:

	UPROPERTY()
	UGMCHUD* PlayerHUD;
	UPROPERTY(EditAnywhere, Category = "HUD")
	TSubclassOf<UGMCHUD> PlayerHUD_Class;
	UPROPERTY()
	UGMCInteractPopUp* InteractionPopUp;
	UPROPERTY(EditAnywhere, Category = "HUD")
	TSubclassOf<UGMCInteractPopUp> InteractionPopUpClass;

protected:
	
	virtual void BeginPlay() override;

private:

	UPROPERTY()
	APlayerController* PC = nullptr;

public:

	UFUNCTION(BlueprintCallable)
	void HideInteractionPopUp();
	UFUNCTION(BlueprintCallable)
	void ShowInteractionPopUp();
	UFUNCTION(BlueprintCallable)
	void HideHUD();
	UFUNCTION(BlueprintCallable)
	void ShowHUD();
	UFUNCTION(BlueprintPure)
	UGMCHUD* GetHUD() {return PlayerHUD;}
};
