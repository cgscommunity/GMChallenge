// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/GMCPlayerController.h"
#include "Characters/GMCHero.h"
#include "GameFramework/CharacterMovementComponent.h"


AGMCPlayerController::AGMCPlayerController()
{
	
	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookRate = 45.f;

	bLockPlayerMovement = false;
}

void AGMCPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent)
	{
		// Set up gameplay key bindings
		InputComponent->BindAction("Jump", IE_Pressed, this, &AGMCPlayerController::RequestJump);
		InputComponent->BindAction("Jump", IE_Released, this, &AGMCPlayerController::RequestStopJump);

		InputComponent->BindAction(TEXT("Crouch"), EInputEvent::IE_Pressed, this, &AGMCPlayerController::RequestCrouchStart);
		InputComponent->BindAction(TEXT("Crouch"), EInputEvent::IE_Released, this, &AGMCPlayerController::RequestCrouchEnd);
		InputComponent->BindAction(TEXT("Sprint"), EInputEvent::IE_Pressed, this, &AGMCPlayerController::RequestSprintStart);
		InputComponent->BindAction(TEXT("Sprint"), EInputEvent::IE_Released, this, &AGMCPlayerController::RequestSprintEnd);

		InputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AGMCPlayerController::RequestAttack);
		InputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Released, this, &AGMCPlayerController::RequestStopJAttack);
		
		InputComponent->BindAxis("MoveForward", this, &AGMCPlayerController::RequestMoveForward);
		InputComponent->BindAxis("MoveRight", this, &AGMCPlayerController::RequestMoveRight);
		InputComponent->BindAxis("Turn", this, &AGMCPlayerController::RequestTurn);
		InputComponent->BindAxis("LookUp", this, &AGMCPlayerController::RequestLook);
	}
}

void AGMCPlayerController::BeginPlay()
{
	Super::BeginPlay();

	GMCHero = Cast<AGMCHero>(GetCharacter());
}


void AGMCPlayerController::RequestMoveForward(float AxisValue)
{
	if (!bLockPlayerMovement)
	{
		if (AxisValue != 0.f)
		{
			FRotator const ControlSpaceRot = GetControlRotation();
			// transform to world space and add it
			GetPawn()->AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::X), AxisValue);
			if  (MovementStatus != EMovementStatus::Jumping)
			{
				MovementStatus = EMovementStatus::Walking;
			}
		}
		else if (GetPawn()->GetVelocity().Size() == 0.f && MovementStatus != EMovementStatus::Jumping)
		{
			MovementStatus = EMovementStatus::Idle;
		}	
	}
}

void AGMCPlayerController::RequestMoveRight(float AxisValue)
{
	if (!bLockPlayerMovement)
	{
		if (AxisValue != 0.f)
		{
			FRotator const ControlSpaceRot = GetControlRotation();
			// transform to world space and add it
			GetPawn()->AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::Y), AxisValue);
			if  (MovementStatus != EMovementStatus::Jumping)
			{
				MovementStatus = EMovementStatus::Walking;
			}
		}
		else if (GetPawn()->GetVelocity().Size() == 0.f && MovementStatus != EMovementStatus::Jumping)
		{
			MovementStatus = EMovementStatus::Idle;
		}	
	}
}

void AGMCPlayerController::RequestLook(float AxisValue)
{
	AddPitchInput(AxisValue * BaseLookRate * GetWorld()->GetDeltaSeconds());
}

void AGMCPlayerController::RequestTurn(float AxisValue)
{
	AddYawInput(AxisValue * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AGMCPlayerController::RequestJump()
{
	if (!bLockPlayerMovement)
	{
		if (GMCHero)
		{
			MovementStatus = EMovementStatus::Jumping;
			GMCHero->Jump();
		}
	}
}

void AGMCPlayerController::RequestStopJump()
{
	if (!bLockPlayerMovement)
	{
		if (GetCharacter())
		{
			GMCHero->StopJumping();
			MovementStatus = EMovementStatus::Idle;
		}
	}
}

void AGMCPlayerController::RequestAttack()
{
	if (!bLockPlayerMovement)
	{
		if (GMCHero)
		{
			GMCHero->PlayAttackMontage();
			ActionStatus = EActionStatus::Attacking;
		}
	}
}

void AGMCPlayerController::RequestStopJAttack()
{
	if (!bLockPlayerMovement)
	{
		ActionStatus = EActionStatus::None;
	}
}

void AGMCPlayerController::RequestCrouchStart()
{
	if (!bLockPlayerMovement)
	{
		if (!GMCHero->GetCharacterMovement()->IsMovingOnGround())
		{
			return;
		}
		if (GMCHero)
		{
			GMCHero->Crouch();
			MovementStatus = EMovementStatus::Crouching;
		}
	}
}

void AGMCPlayerController::RequestCrouchEnd()
{
	if (!bLockPlayerMovement)
	{
		if (GMCHero)
		{
			GMCHero->UnCrouch();
			MovementStatus = EMovementStatus::Idle;
		}
	}
}

void AGMCPlayerController::RequestSprintStart()
{
	if (!bLockPlayerMovement)
	{
		MovementStatus = EMovementStatus::Sprinting;
	}
}

void AGMCPlayerController::RequestSprintEnd()
{
	if (!bLockPlayerMovement)
	{
		if (GMCHero)
		{
			if (GMCHero->GetVelocity().Size() > 0.f)
			{
				MovementStatus = EMovementStatus::Walking;
			}
			else
			{
				MovementStatus = EMovementStatus::Idle;
			}
		}
	}
}
