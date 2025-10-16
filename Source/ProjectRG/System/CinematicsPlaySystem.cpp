// Fill out your copyright notice in the Description page of Project Settings.


#include "System/CinematicsPlaySystem.h"
#include "LevelSequence.h"
#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "MovieScene.h"
#include "MovieSceneSequencePlayer.h"

ACinematicsPlaySystem::ACinematicsPlaySystem()
{
 	PrimaryActorTick.bCanEverTick = true;
}

void ACinematicsPlaySystem::InitSeqActor()
{
	TArray<AActor*> EnemyActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Enemy"), EnemyActors);
	if (EnemyActors.IsEmpty()) return;
	UE_LOG(LogTemp, Log, TEXT("Enemy Actors Not Empty"));

	PlayerActor = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	EnemyActor = EnemyActors[0];
	SeqActor = GetWorld()->SpawnActor<ALevelSequenceActor>(ALevelSequenceActor::StaticClass());	
}

void ACinematicsPlaySystem::InitSeqData()
{
	ULevelSequence* PlayerOverviewSequence = LoadObject<ULevelSequence>(nullptr, TEXT("/Game/Cinematics/Overview/PlayerOverview_LevelSequence.PlayerOverview_LevelSequence"));
	TargetSeqByIndex.Add(0, PlayerOverviewSequence);
	TargetActorBySeq.Add(PlayerOverviewSequence, PlayerActor);
}

void ACinematicsPlaySystem::PlayCinematicByIndex(int32 Index)
{	
	ULevelSequence** FoundSeq = TargetSeqByIndex.Find(Index);
	if (FoundSeq == nullptr) return;
	ULevelSequence* TargetSeq = *FoundSeq;

	AActor** FoundActor = TargetActorBySeq.Find(TargetSeq);
	if (FoundActor == nullptr) return;
	AActor* TargetActor = *FoundActor;

	SeqActor->GetSequencePlayer()->Stop();
	SeqActor->SetSequence(TargetSeq);

	FMovieSceneObjectBindingID BindingID = SeqActor->GetSequence()->FindBindingByTag(FName("Actor"));
	SeqActor->SetBinding(BindingID, TArray<AActor*>{TargetActor}, true);

	SeqActor->GetSequencePlayer()->Play();

	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(PlayerActor);
	PlayerCharacter->SetState(EPlayerState::Waiting);
}

void ACinematicsPlaySystem::PlayCinematicByPlayerState(EPlayerState State)
{
	ULevelSequence* TargetSeq = TargetSeqByState[State];
	if (TargetSeq == nullptr) return;

	AActor* TargetActor = TargetActorBySeq[TargetSeq];
	if (TargetActor == nullptr) return;

	SeqActor->GetSequencePlayer()->Stop();
	SeqActor->SetSequence(TargetSeq);

	FMovieSceneObjectBindingID BindingID = SeqActor->GetSequence()->FindBindingByTag(FName("Player"));
	SeqActor->SetBinding(BindingID, TArray<AActor*>{TargetActor}, true);

	SeqActor->GetSequencePlayer()->Play();
}

void ACinematicsPlaySystem::BeginPlay()
{
	Super::BeginPlay();
	
	InitSeqActor();
	InitSeqData();
}
