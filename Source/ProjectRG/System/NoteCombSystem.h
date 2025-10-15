// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NoteCombData.h"
#include "NoteCombSystem.generated.h"

struct FMeasureData;
class UNoteCombWidget;

UCLASS()
class PROJECTRG_API ANoteCombSystem : public AActor
{
	GENERATED_BODY()
	
public:	
	ANoteCombSystem();

	void InitWidget();
	void TryAddNoteA(float MusicElapsedTime, FMeasureData CurMeasureData, float Threshold);
	void SwitchNoteComb();
	void UpdateCurNoteCombWidget();

protected:
	virtual void BeginPlay() override;

protected:
	float InputOffset;
	FNoteCombData CurNoteCombData;
	FNoteCombData NextNoteCombData;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG")
	TSubclassOf<UNoteCombWidget> NoteCombWidgetClass;
	UPROPERTY(BlueprintReadOnly, Category = "UMG")
	UNoteCombWidget* NoteCombWidget;
};
