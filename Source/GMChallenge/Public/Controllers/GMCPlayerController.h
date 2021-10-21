// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GMCPlayerController.generated.h"

UENUM(BlueprintType)
enum EMovementStatus
{
	Idle     UMETA(DisplayName = "Idle"),
	Walking     UMETA(DisplayName = "Walking"),
	Sprinting     UMETA(DisplayName = "Sprinting"),
	Jumping     UMETA(DisplayName = "Jumping"),
	Crouching     UMETA(DisplayName = "Crouching"),
};

UENUM(BlueprintType)
enum EActionStatus
{
	None     UMETA(DisplayName = "None"),
	Attacking     UMETA(DisplayName = "Attacking"),
};

UCLASS()
class GMCHALLENGE_API AGMCPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AGMCPlayerController();

	UPROPERTY()
	class AGMCHero* GMCHero = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "Movement Status")
	TEnumAsByte<EMovementStatus> MovementStatus;
	UPROPERTY(BlueprintReadWrite, Category = "Movement Status")
	TEnumAsByte<EActionStatus> ActionStatus;
	
	UPROPERTY(EditAnywhere, Category = "Look")
	float BaseLookRate = 90.0f;
	UPROPERTY(EditAnywhere, Category = "Look")
	float BaseTurnRate = 90.0f;
	
	void RequestMoveForward(float Value);
	void RequestMoveRight(float Value);
	void RequestLook(float AxisValue);
	void RequestTurn(float AxisValue);

	void RequestJump();
	void RequestStopJump();

	void RequestAttack();
	void RequestStopJAttack();

	void RequestCrouchStart();
	void RequestCrouchEnd();

	void RequestSprintStart();
	void RequestSprintEnd();

	UFUNCTION(BlueprintPure)
	EMovementStatus GetMovementStatus() {return MovementStatus;}
	UFUNCTION(BlueprintPure)
	EActionStatus GetActionStatus() {return ActionStatus;}

	UFUNCTION(BlueprintCallable)
	void SetMovementStatus(EMovementStatus const NewStatus) {MovementStatus = NewStatus;}
	UFUNCTION(BlueprintCallable)
	void SetActionStatus(EActionStatus const NewStatus) {ActionStatus = NewStatus;}
	UFUNCTION(BlueprintCallable)
    void LockPlayerMovement(bool bShouldLock) {bLockPlayerMovement = bShouldLock;}

protected:
	
	void SetupInputComponent() override;
	virtual void BeginPlay() override;
	
	bool bLockPlayerMovement;	
};
