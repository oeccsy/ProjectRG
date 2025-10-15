// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "RGPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

class ARGGameMode;
class AMusicPlaySystem;
class ACinematicsPlaySystem;


UCLASS()
class PROJECTRG_API ARGPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	void OnHitNoteA(const FInputActionValue& Value);
	void OnHitNoteS(const FInputActionValue& Value);
	void OnHitNoteD(const FInputActionValue& Value);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* HitNoteA;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* HitNoteS;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* HitNoteD;

	ARGGameMode* GameModeRef;
};
