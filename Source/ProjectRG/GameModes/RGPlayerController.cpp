// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/RGPlayerController.h"
#include "GameModes/RGGameMode.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "MusicPlaySystem.h"
#include "NoteCombSystem.h"

void ARGPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}

	GameModeRef = Cast<ARGGameMode>(GetWorld()->GetAuthGameMode());
}

void ARGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(InputComponent))
	{
		Input->BindAction(HitNoteA, ETriggerEvent::Triggered, this, &ARGPlayerController::OnHitNoteA);
		Input->BindAction(HitNoteS, ETriggerEvent::Triggered, this, &ARGPlayerController::OnHitNoteS);
		Input->BindAction(HitNoteD, ETriggerEvent::Triggered, this, &ARGPlayerController::OnHitNoteD);
	}
}

void ARGPlayerController::OnHitNoteA(const FInputActionValue& Value)
{
	float MusicElapsedTime = GameModeRef->MusicPlaySystem->GetMusicElapsedTime();
	FMeasureData CurMeasureData = GameModeRef->MusicPlaySystem->GetCurMeasureData();

	GameModeRef->NoteCombSystem->TryAddNoteA(MusicElapsedTime, CurMeasureData, 0.1f);
	GameModeRef->NoteCombSystem->UpdateCurNoteCombWidget();
}

void ARGPlayerController::OnHitNoteS(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Log, TEXT("OnHItNoteS"));
	GameModeRef->MusicPlaySystem->StartMusic(0.2f);
}

void ARGPlayerController::OnHitNoteD(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Log, TEXT("OnHItNoteD"));
}