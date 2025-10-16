// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RGGameMode.generated.h"

class AMusicPlaySystem;
class ANoteCombSystem;
class ACinematicsPlaySystem;
class ASkillExecuteSystem;

UCLASS()
class PROJECTRG_API ARGGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnMeasureBegin();

protected:
	virtual void BeginPlay() override;
	
public:
	UPROPERTY(VisibleAnywhere, Category = "System")
	AMusicPlaySystem* MusicPlaySystem;
	UPROPERTY(VisibleAnywhere, Category = "System")
	ANoteCombSystem* NoteCombSystem;
	UPROPERTY(VisibleAnywhere, Category = "System")
	ACinematicsPlaySystem* CinematicsPlaySystem;
	UPROPERTY(VisibleAnywhere, Category = "System")
	ASkillExecuteSystem* SkillExecuteSystem;

private:
	UPROPERTY(EditDefaultsOnly, Category = "System")
	TSubclassOf<AMusicPlaySystem> MusicPlaySystemClass;

	UPROPERTY(EditDefaultsOnly, Category = "System")
	TSubclassOf<ANoteCombSystem> NoteCombSystemClass;
	
	UPROPERTY(EditDefaultsOnly, Category = "System")
	TSubclassOf<ACinematicsPlaySystem> CinematicsPlaySystemClass;
	
	UPROPERTY(EditDefaultsOnly, Category = "System")
	TSubclassOf<ASkillExecuteSystem> SkillExecuteSystemClass;
};
