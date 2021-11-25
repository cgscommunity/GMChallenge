// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "GMCInteractPopUp.generated.h"

USTRUCT(BlueprintType)
struct FInteractPopUpDetails
{
	GENERATED_BODY()

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interact PopUp")
	FText InteractInput = FText::FromString("E");
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interact PopUp")
	FText InteractText = FText::FromString("Interact");
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interact PopUp")
	FSlateBrush BorderBrush;
};


UCLASS()
class GMCHALLENGE_API UGMCInteractPopUp : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintPure)
	FInteractPopUpDetails GetInteractPopUpDetails() const {return PopupDetails;} 
	UFUNCTION(BlueprintCallable)
	void SetInteractPopUpDetails(FText InteractInputBinding, FText InteractionText, FSlateBrush Background);
		
private:

	FInteractPopUpDetails PopupDetails;
	
};
