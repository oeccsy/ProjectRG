// Fill out your copyright notice in the Description page of Project Settings.


#include "System/SkillExecuteSystem.h"
#include "Skill/Skill.h"
#include "Skill/PunchSkill.h"
#include "Data/NoteCombData.h"

ASkillExecuteSystem::ASkillExecuteSystem()
{
 	PrimaryActorTick.bCanEverTick = true;
}

void ASkillExecuteSystem::RegisterSkills()
{
	SkillTable.Add(TEXT("AAAA"), UPunchSkill::StaticClass());
}

void ASkillExecuteSystem::ExecuteSkill(FNoteCombData NoteComb)
{
	TSubclassOf<USkill>* TargetSkill = SkillTable.Find(NoteComb.Comb);
	if (TargetSkill == nullptr) return;

	USkill* SkillInstance = NewObject<USkill>(*TargetSkill);
	if (SkillInstance->IsSkillValid()) SkillInstance->ExecuteSkill();
}

void ASkillExecuteSystem::BeginPlay()
{
	Super::BeginPlay();

	RegisterSkills();
}