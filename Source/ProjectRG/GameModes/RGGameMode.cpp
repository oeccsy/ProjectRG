// Fill out your copyright notice in the Description page of Project Settings.


#include "RGGameMode.h"
#include "MusicPlaySystem.h"
#include "NoteCombSystem.h"
#include "CinematicsPlaySystem.h"
#include "SkillExecuteSystem.h"
#include "Player/PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"

void ARGGameMode::OnMeasureBegin()
{
	UE_LOG(LogTemp, Log, TEXT("OnMeasureBegin"));

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (PlayerPawn == nullptr) return;
	
	UE_LOG(LogTemp, Log, TEXT("Pawn Found"));

	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(PlayerPawn);
	if (PlayerCharacter == nullptr) return;

	UE_LOG(LogTemp, Log, TEXT("PlayerCharacter Cast"));

	PlayerCharacter->UpdateState();
	NoteCombSystem->SwitchNoteComb();

	int MeasureIndex = MusicPlaySystem->GetCurMeasureData().Index;
	CinematicsPlaySystem->PlayCinematicByIndex(MeasureIndex);
}

void ARGGameMode::BeginPlay()
{
	Super::BeginPlay();

	MusicPlaySystem = GetWorld()->SpawnActor<AMusicPlaySystem>(MusicPlaySystemClass, FVector::ZeroVector, FRotator::ZeroRotator);
	NoteCombSystem = GetWorld()->SpawnActor<ANoteCombSystem>(NoteCombSystemClass, FVector::ZeroVector, FRotator::ZeroRotator);
	CinematicsPlaySystem = GetWorld()->SpawnActor<ACinematicsPlaySystem>(CinematicsPlaySystemClass, FVector::ZeroVector, FRotator::ZeroRotator);
	SkillExecuteSystem = GetWorld()->SpawnActor<ASkillExecuteSystem>(SkillExecuteSystemClass, FVector::ZeroVector, FRotator::ZeroRotator);

	if (MusicPlaySystem)
	{
		UE_LOG(LogTemp, Log, TEXT("Bind OnMeasureBegin"));
		MusicPlaySystem->OnMeasureBegin.AddDynamic(this, &ARGGameMode::OnMeasureBegin);
	}
}