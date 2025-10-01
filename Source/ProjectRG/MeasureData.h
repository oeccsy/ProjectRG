// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MeasureData.generated.h"

USTRUCT(BlueprintType)
struct FMeasureData
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Measure")
	int32 Index;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Measure")
	float MeasureBeginTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Measure")
	float Duration;
};
