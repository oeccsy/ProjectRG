// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "PlayerCharacter.generated.h"

class UInputMappingContext;
class UInputAction;

UENUM(BlueprintType)
enum class EPlayerState : uint8
{
	Idle UMETA(DisplayName = "Idle"),
	CastPunch UMETA(DisplayName = "CastPunch"),
	CastPowerPunch UMETA(DisplayName = "CastPowerPunch"),
	Punch UMETA(DisplayName = "Punch"),
	CastFire UMETA(DisplayName = "CastFire"),
	Fire UMETA(DisplayName = "Fire"),
	Waiting UMETA(DisplayName = "Waiting")
};


UCLASS()
class PROJECTRG_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

public:	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Move(FVector2D MovementVector);
	void UpdateState();
	void SetState(EPlayerState NextState);
	void CastPunch();
	void Punch();

protected:
	void OnMove(const FInputActionValue& Value);
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UCapsuleComponent* CollisionCylinder;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UArrowComponent* Arrow;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USkeletalMeshComponent* CharacterMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UCameraComponent* Camera;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "State")
	EPlayerState CurState = EPlayerState::Idle;
};
