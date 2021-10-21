// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GMCHero.generated.h"

UCLASS()
class GMCHALLENGE_API AGMCHero : public ACharacter
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* WeaponCollision;
	
public:

	AGMCHero();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	UStaticMeshComponent* Weapon;
	UPROPERTY(EditAnywhere, Category = "Animation")
	UAnimMontage* AttackMontage = nullptr;
	
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	bool bWeaponEquipped;
	
	UFUNCTION(BlueprintPure)
	bool GetIsWeaponEquipped(){return bWeaponEquipped;}

	void PlayAttackMontage();

protected:

	virtual void BeginPlay() override;
	
};
