// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	CollisionCylinder = GetCapsuleComponent();
	
	Arrow = FindComponentByClass<UArrowComponent>();
	Arrow->SetupAttachment(RootComponent);

	CharacterMesh = GetMesh();
	CharacterMesh->SetupAttachment(RootComponent);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SplingArm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(InputComponent))
	{
		Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacter::OnMove);
	}
}

void APlayerCharacter::Move(FVector2D MovementVector)
{
	FRotator ControlRotation = GetControlRotation();
	FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);

	const FVector ForwardVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(ForwardVector, MovementVector.Y);
	AddMovementInput(RightVector, MovementVector.X);
}

void APlayerCharacter::UpdateState()
{
	switch (CurState)
	{
	case EPlayerState::Idle:
		break;
	case EPlayerState::CastPunch:
		break;
	case EPlayerState::CastPowerPunch:
		break;
	case EPlayerState::Punch:
		break;
	case EPlayerState::CastFire:
		break;
	}
}

void APlayerCharacter::SetState(EPlayerState NextState)
{
	CurState = NextState;
}

void APlayerCharacter::CastPunch()
{
	CurState = EPlayerState::CastPunch;
}

void APlayerCharacter::Punch()
{
	CurState = EPlayerState::Punch;
}

void APlayerCharacter::OnMove(const FInputActionValue& Value)
{
	Move(Value.Get<FVector2D>());
}

