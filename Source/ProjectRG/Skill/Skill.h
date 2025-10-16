// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Skill.generated.h"

UCLASS(Abstract)
class PROJECTRG_API USkill : public UObject
{
	GENERATED_BODY()
	
public:
	virtual bool IsSkillValid() PURE_VIRTUAL(USkill::IsSkillValid, return false;);
	virtual void ExecuteSkill() PURE_VIRTUAL(USkill::ExecuteSkill, );
};
