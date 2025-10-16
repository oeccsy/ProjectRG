// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Skill/Skill.h"
#include "PunchSkill.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTRG_API UPunchSkill : public USkill
{
	GENERATED_BODY()
	
public:
	virtual bool IsSkillValid() override;
	virtual void ExecuteSkill() override;
};
