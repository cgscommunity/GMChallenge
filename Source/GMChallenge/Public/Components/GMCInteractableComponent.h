// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UI/GMCInteractPopUp.h"
#include "GMCInteractableComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInteract);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDisplayInteractionPopUp);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHideInteractionPopUp);

class AGMCGameMode;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GMCHALLENGE_API UGMCInteractableComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGMCInteractableComponent();

	UPROPERTY(BlueprintReadOnly)
	AGMCGameMode* GameMode;
	UPROPERTY(EditAnywhere, Category = "Game Mode")
	TSubclassOf<AGMCGameMode> InteractionPopUpClass;
	UPROPERTY(EditAnywhere, Category = "Interact")
	FInteractPopUpDetails InteractPopUpDetails;

	UPROPERTY(BlueprintAssignable)
	FInteract OnInteract;
	UPROPERTY(BlueprintAssignable)
	FDisplayInteractionPopUp OnDisplayInteractionPopUp;
	UPROPERTY(BlueprintAssignable)
	FHideInteractionPopUp OnHideInteractionPopUp;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void CallDisplayPopUp();
	UFUNCTION(BlueprintCallable)
	void CallHidePopUp();
	UFUNCTION(BlueprintCallable)
	void CallInteract();
};
