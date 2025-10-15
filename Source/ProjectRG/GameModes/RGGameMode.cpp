// Fill out your copyright notice in the Description page of Project Settings.


#include "RGGameMode.h"
#include "MusicPlaySystem.h"
#include "NoteCombSystem.h"
#include "CinematicsPlaySystem.h"
#include "SkillExecuteSystem.h"

void ARGGameMode::BeginPlay()
{
	MusicPlaySystem = GetWorld()->SpawnActor<AMusicPlaySystem>(MusicPlaySystemClass, FVector::ZeroVector, FRotator::ZeroRotator);
	NoteCombSystem = GetWorld()->SpawnActor<ANoteCombSystem>(NoteCombSystemClass, FVector::ZeroVector, FRotator::ZeroRotator);
	CinematicsPlaySystem = GetWorld()->SpawnActor<ACinematicsPlaySystem>(CinematicsPlaySystemClass, FVector::ZeroVector, FRotator::ZeroRotator);
	SkillExecuteSystem = GetWorld()->SpawnActor<ASkillExecuteSystem>(SkillExecuteSystemClass, FVector::ZeroVector, FRotator::ZeroRotator);

	if (MusicPlaySystem)
	{
		//MusicPlaySystem->OnMeasureBegin.AddDynamic(this, &ARGGameMode::OnMusi)
	}
}