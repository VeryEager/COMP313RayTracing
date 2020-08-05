// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectibleItemSpawner.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "CollectibleFlowerActor.h"

// Sets default values
ACollectibleItemSpawner::ACollectibleItemSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnedItem = nullptr;
	SpawnDelayMin = 4.0f;
	SpawnDelayMax = 3.0f * SpawnDelayMin;

	RandSpawnDelay = -1;

	//this code initializes a Flower Blueprint instead of the CollectibleFlowerActor class.
	static ConstructorHelpers::FObjectFinder<UBlueprint> CollectibleItemBlueprint(TEXT("Blueprint'/Game/Flower.Flower'"));
	if (CollectibleItemBlueprint.Object) {
		FlowerItemBlueprint = (UClass*)CollectibleItemBlueprint.Object->GeneratedClass;
	}
}

// Called when the game starts or when spawned
void ACollectibleItemSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACollectibleItemSpawner::SetNextSpawn() 
{
	//check to see if we've begun spawning process
	if (RandSpawnDelay < 0) {
		RandSpawnDelay = FMath::RandRange(SpawnDelayMin, SpawnDelayMax);

		FTimerHandle TimerHandle;

		GetWorldTimerManager().SetTimer(TimerHandle, this, &ACollectibleItemSpawner::RespawnItem, RandSpawnDelay, false);
	}	
}

void ACollectibleItemSpawner::RespawnItem()
{
	const FActorSpawnParameters SpawnParams;	
	//remove "FlowerItemBlueprint" arg for a CollectibleFlowerActor
	SpawnedItem = GetWorld()->SpawnActor<ACollectibleFlowerActor>(GetActorLocation(), GetActorRotation(), SpawnParams);
	RandSpawnDelay = -1;
}

// Called every frame
void ACollectibleItemSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (SpawnedItem == nullptr || SpawnedItem->IsPendingKillPending()) {
		SetNextSpawn();
	}
}

