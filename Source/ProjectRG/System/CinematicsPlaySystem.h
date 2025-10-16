// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Player/PlayerCharacter.h"
#include "CinematicsPlaySystem.generated.h"

class ALevelSequenceActor;
class ULevelSequence;

UCLASS()
class PROJECTRG_API ACinematicsPlaySystem : public AActor
{
	GENERATED_BODY()
	
public:	
	ACinematicsPlaySystem();

	void InitSeqActor();
	void InitSeqData();
	void PlayCinematicByIndex(int32 Index);
	void PlayCinematicByPlayerState(EPlayerState State);

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Actor")
	AActor* PlayerActor;
	UPROPERTY(VisibleAnywhere, Category = "Actor")
	AActor* EnemyActor;

	UPROPERTY(VisibleAnywhere, Category = "LevelSequence")
	ALevelSequenceActor* SeqActor;
	UPROPERTY(VisibleAnywhere, Category = "LevelSequence")
	TMap<int32, ULevelSequence*> TargetSeqByIndex;
	UPROPERTY(VisibleAnywhere, Category = "LevelSequence")
	TMap<EPlayerState, ULevelSequence*> TargetSeqByState;
	UPROPERTY(VisibleAnywhere, Category = "LevelSequence")
	TMap<ULevelSequence*, AActor*> TargetActorBySeq;
};
