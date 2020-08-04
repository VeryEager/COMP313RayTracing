// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollectibleItemSpawner.generated.h"

UCLASS()
class ASSIGNMENTGAME_API ACollectibleItemSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectibleItemSpawner();

	TSubclassOf<class ACollectibleFlowerActor> FlowerItemBlueprint;

	//the object of item spawned
	class ACollectibleFlowerActor* SpawnedItem;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Spawn Properties")
	float SpawnDelayMin;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Spawn Properties")
	float SpawnDelayMax;

	int RandSpawnDelay;
	int64 StartingSysTime;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//should be called when the SpawnedItem is removed
	virtual void SetNextSpawn();

	//Respawns the item into the world
	virtual void RespawnItem();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
