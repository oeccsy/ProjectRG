// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/AudioComponent.h"

#include "MeasureData.h"
#include "NoteData.h"

#include "MusicPlaySystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMeasureBeginSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNoteBeginSignature);

UCLASS()
class PROJECTRG_API AMusicPlaySystem : public AActor
{
	GENERATED_BODY()
	
public:	
	AMusicPlaySystem();

protected:
	virtual void BeginPlay() override;
	void LoadDataTable(UDataTable* MeasureDataTable);

public:
	void StartMusic(float Offset = 0.0f);
	float GetMusicElapsedTime();
	FMeasureData GetCurMeasureData();

protected:
	virtual void Tick(float DeltaTime) override;
	void UpdateMeasureInfo();
	void UpdateNoteInfo();

public:
	UPROPERTY(BlueprintAssignable)
	FOnMeasureBeginSignature OnMeasureBegin;
	UPROPERTY(BlueprintAssignable)
	FOnNoteBeginSignature OnNoteBegin;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Music")
	UAudioComponent* Audio;

	UPROPERTY(VisibleAnywhere, Category = "Music")
	float MusicStartTime;
	UPROPERTY(VisibleAnywhere, Category = "Music")
	float MusicElapsedTime;

	UPROPERTY(VisibleAnywhere, Category = "Music")
	FMeasureData CurMeasureData;
	UPROPERTY(VisibleAnywhere, Category = "Music")
	FNoteData CurNoteData;

	UPROPERTY(EditAnywhere, Category = "Music")
	UDataTable* MeasureDataTable;
	UPROPERTY(VisibleAnywhere, Category = "Music")
	TArray<FMeasureData> MeasureDataArray;
};
