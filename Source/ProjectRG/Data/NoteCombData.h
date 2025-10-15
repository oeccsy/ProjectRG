// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NoteCombData.generated.h"

USTRUCT(BlueprintType)
struct FNoteCombData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Comb;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CombSuccess;
	
	UPROPERTY(EditAnywhere)
	int NoteUseCount[8];
};
