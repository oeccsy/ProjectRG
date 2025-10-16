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

	void TryAddNoteA(float MusicElapsedTime, FMeasureData CurMeasureData, float Threshold);
	UFUNCTION()
	void SwitchNoteComb();
	
protected:
	virtual void BeginPlay() override;
	void UpdateCurNoteCombWidget();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NoteComb")
	float InputOffset;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NoteComb")
	FNoteCombData CurNoteCombData;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NoteComb")
	FNoteCombData NextNoteCombData;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG")
	TSubclassOf<UNoteCombWidget> NoteCombWidgetClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UMG")
	UNoteCombWidget* NoteCombWidget;
};
