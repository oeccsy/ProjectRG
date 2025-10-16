// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SkillExecuteSystem.generated.h"

struct FNoteCombData;

UCLASS()
class PROJECTRG_API ASkillExecuteSystem : public AActor
{
	GENERATED_BODY()
	
public:	
	ASkillExecuteSystem();

	void RegisterSkills();
	void ExecuteSkill(FNoteCombData NoteComb);

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Skill")
	TMap<FString, TSubclassOf<class USkill>> SkillTable;
};
