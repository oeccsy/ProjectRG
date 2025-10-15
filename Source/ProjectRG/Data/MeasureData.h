// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MeasureData.generated.h"

USTRUCT(BlueprintType)
struct FMeasureData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Measure")
	int32 Index;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Measure")
	float MeasureBeginTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Measure")
	float Duration;
};