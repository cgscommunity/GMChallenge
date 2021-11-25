// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/GMCInteractableComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameModes/GMCGameMode.h"

// Sets default values for this component's properties
UGMCInteractableComponent::UGMCInteractableComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGMCInteractableComponent::BeginPlay()
{
	Super::BeginPlay();

	GameMode = Cast<AGMCGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
	{
		OnDisplayInteractionPopUp.AddDynamic(GameMode, &AGMCGameMode::ShowInteractionPopUp);
		OnHideInteractionPopUp.AddDynamic(GameMode, &AGMCGameMode::HideInteractionPopUp);
	}
}


// Called every frame
void UGMCInteractableComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGMCInteractableComponent::CallDisplayPopUp()
{
	if (GameMode && GameMode->InteractionPopUp)
	{
		GameMode->InteractionPopUp->SetInteractPopUpDetails(InteractPopUpDetails.InteractInput, InteractPopUpDetails.InteractText, InteractPopUpDetails.BorderBrush);
	}
	OnDisplayInteractionPopUp.Broadcast();
}

void UGMCInteractableComponent::CallHidePopUp()
{
	OnHideInteractionPopUp.Broadcast();
}

void UGMCInteractableComponent::CallInteract()
{
	OnInteract.Broadcast();
}

