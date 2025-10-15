// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicPlaySystem.h"

AMusicPlaySystem::AMusicPlaySystem() : MusicStartTime(0.0f), MusicElapsedTime(0.0f), CurMeasureData({}), CurNoteData({})
{
	PrimaryActorTick.bCanEverTick = true;

	Audio = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	RootComponent = Audio;
}

void AMusicPlaySystem::BeginPlay()
{
	Super::BeginPlay();

	LoadDataTable(MeasureDataTable);
}

void AMusicPlaySystem::LoadDataTable(UDataTable* InMeasureDataTable)
{
	if (!InMeasureDataTable) return;

	for (const FName& RowName : InMeasureDataTable->GetRowNames())
	{
		FMeasureData* MeasureData = InMeasureDataTable->FindRow<FMeasureData>(RowName, TEXT(""));
		if (MeasureData) MeasureDataArray.Add(*MeasureData);
	}
}

void AMusicPlaySystem::StartMusic(float Offset)
{
	MusicStartTime = GetGameTimeSinceCreation() + Offset;
	MusicElapsedTime = 0.0f;

	CurMeasureData.Index = -1;
	CurMeasureData.MeasureBeginTime = 0.0;
	CurMeasureData.Duration = 0.0f;

	CurNoteData.Index = -1;
	CurNoteData.NoteTime = 0.0f;
	CurNoteData.Interval = 0.0f;

	Audio->Play();
}

float AMusicPlaySystem::GetMusicElapsedTime()
{
	return MusicElapsedTime;
}

FMeasureData AMusicPlaySystem::GetCurMeasureData()
{
	return CurMeasureData;
}

void AMusicPlaySystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateMeasureInfo();
	UpdateNoteInfo();
}

void AMusicPlaySystem::UpdateMeasureInfo()
{
	if (MusicStartTime <= 0.0f) return;

	MusicElapsedTime = GetGameTimeSinceCreation() - MusicStartTime;
	bool IsNewMeasureBegin = CurMeasureData.MeasureBeginTime + CurMeasureData.Duration <= MusicElapsedTime;

	if (IsNewMeasureBegin)
	{
		CurMeasureData = MeasureDataArray[CurMeasureData.Index + 1];
		OnMeasureBegin.Broadcast();

		FString NewMeasureTime = FString::SanitizeFloat(CurMeasureData.MeasureBeginTime);
		UE_LOG(LogTemp, Log, TEXT("New Measure : %s"), *NewMeasureTime);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("New Measure : ") + NewMeasureTime);
	}
}

void AMusicPlaySystem::UpdateNoteInfo()
{
	if (MusicStartTime <= 0.0f) return;

	MusicElapsedTime = GetGameTimeSinceCreation() - MusicStartTime;
	bool IsNewNoteTime = CurNoteData.NoteTime + CurNoteData.Interval <= MusicElapsedTime;

	if (IsNewNoteTime)
	{
		CurNoteData.Index = (CurNoteData.Index + 1) % 8;
		CurNoteData.NoteTime = CurNoteData.NoteTime + CurNoteData.Interval;
		CurNoteData.Interval = CurMeasureData.Duration / 8.0f;
		OnNoteBegin.Broadcast();

		FString NewNoteTime = FString::SanitizeFloat(CurNoteData.NoteTime);
		UE_LOG(LogTemp, Log, TEXT("New Note : %s"), *NewNoteTime);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("New Note : ") + NewNoteTime);
	}
}