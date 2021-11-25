// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GMCInteractPopUp.h"
#include "Styling/SlateBrush.h"

void UGMCInteractPopUp::SetInteractPopUpDetails(FText InteractInputBinding, FText InteractionText, FSlateBrush Background)
{
	PopupDetails.InteractInput = InteractInputBinding;
	PopupDetails.InteractText = InteractionText;
	PopupDetails.BorderBrush = Background;
}
