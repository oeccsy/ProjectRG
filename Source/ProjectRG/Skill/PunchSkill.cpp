// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill/PunchSkill.h"
#include "PunchSkill.h"

bool UPunchSkill::IsSkillValid()
{
	UE_LOG(LogTemp, Log, TEXT("Punch SKill: IsSkillValid"));
	return true;
}

void UPunchSkill::ExecuteSkill()
{
	UE_LOG(LogTemp, Log, TEXT("Execute Skill"));
}
