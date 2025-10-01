// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NoteData.generated.h"

USTRUCT(BlueprintType)
struct FNoteData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Index;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float NoteTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Interval;
};
