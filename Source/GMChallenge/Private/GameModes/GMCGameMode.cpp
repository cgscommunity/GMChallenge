// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/GMCGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "UI/GMCHUD.h"
#include "UI/GMCInteractPopUp.h"


void AGMCGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PC)
	{
		if (HUDClass)
		{
			PlayerHUD = CreateWidget<UGMCHUD>(PC, PlayerHUD_Class);
		}
		if (InteractionPopUpClass)
		{
			InteractionPopUp = CreateWidget<UGMCInteractPopUp>(PC, InteractionPopUpClass);
		}
	}
}

void AGMCGameMode::HideInteractionPopUp()
{
	if (InteractionPopUp && InteractionPopUp->IsInViewport())
	{
		InteractionPopUp->RemoveFromViewport();
	}
}

void AGMCGameMode::ShowInteractionPopUp()
{
	if (InteractionPopUp && !InteractionPopUp->IsInViewport())
	{
		InteractionPopUp->AddToViewport();
	}
}

void AGMCGameMode::HideHUD()
{
	if (PlayerHUD)
	{
		PlayerHUD->RemoveFromViewport();
	}
}

void AGMCGameMode::ShowHUD()
{
	if (PlayerHUD)
	{
		PlayerHUD->AddToViewport();
	}
}
