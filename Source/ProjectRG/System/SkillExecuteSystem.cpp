// Fill out your copyright notice in the Description page of Project Settings.


#include "System/SkillExecuteSystem.h"

// Sets default values
ASkillExecuteSystem::ASkillExecuteSystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASkillExecuteSystem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASkillExecuteSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

