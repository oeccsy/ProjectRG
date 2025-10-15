// Fill out your copyright notice in the Description page of Project Settings.


#include "NoteCombSystem.h"
#include "MeasureData.h"
#include "Math/UnrealMathUtility.h"
#include "Blueprint/UserWidget.h"
#include "Widget/NoteCombWidget.h"

ANoteCombSystem::ANoteCombSystem() : InputOffset(0.2f)
{
	PrimaryActorTick.bCanEverTick = true;

	CurNoteCombData = { };
	CurNoteCombData.CombSuccess = true;
	NextNoteCombData = { };
	NextNoteCombData.CombSuccess = true;
}

void ANoteCombSystem::TryAddNoteA(float MusicElapsedTime, FMeasureData CurMeasureData, float Threshold)
{
	float InputTime = MusicElapsedTime + InputOffset;
	float MeasureProgress = (InputTime - CurMeasureData.MeasureBeginTime) / CurMeasureData.Duration;
	int NoteIndex = FMath::RoundToInt(MeasureProgress);

	FNoteCombData& TargetNoteComb = (NoteIndex == 8) ? NextNoteCombData : CurNoteCombData;
	if (NoteIndex == 8) NoteIndex = 0;

	if (TargetNoteComb.NoteUseCount[NoteIndex] > 0) TargetNoteComb.CombSuccess = false;
	if (!TargetNoteComb.CombSuccess) return;
	
	TargetNoteComb.Comb.AppendChar('A');
	++TargetNoteComb.NoteUseCount[NoteIndex];
}

void ANoteCombSystem::SwitchNoteComb()
{
	CurNoteCombData = NextNoteCombData;

	NextNoteCombData = { };
	NextNoteCombData.CombSuccess = true;

	UpdateCurNoteCombWidget();
}

void ANoteCombSystem::UpdateCurNoteCombWidget()
{
	if (!NoteCombWidget) return;

	FText CombText = FText::FromString(CurNoteCombData.Comb);
	FLinearColor TextColor = (CurNoteCombData.CombSuccess) ? FLinearColor::White : FLinearColor::Red;
	
	NoteCombWidget->RefreshNoteCombText(CombText, TextColor);
}

void ANoteCombSystem::BeginPlay()
{
	Super::BeginPlay();
	
	if (NoteCombWidgetClass == nullptr) return;

	NoteCombWidget = CreateWidget<UNoteCombWidget>(GetWorld(), NoteCombWidgetClass);
	NoteCombWidget->AddToViewport();
}