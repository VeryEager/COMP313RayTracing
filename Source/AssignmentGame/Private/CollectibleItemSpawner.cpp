// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectibleItemSpawner.h"

// Sets default values
ACollectibleItemSpawner::ACollectibleItemSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnedItem = NULL;
	SpawnDelayMin = 4.0f;
	SpawnDelayMax = 3.0f * SpawnDelayMin;

}

// Called when the game starts or when spawned
void ACollectibleItemSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACollectibleItemSpawner::SetNextSpawn() 
{

}

// Called every frame
void ACollectibleItemSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

