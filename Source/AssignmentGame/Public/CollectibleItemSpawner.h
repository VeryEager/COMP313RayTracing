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

	//the type of item spawned

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Spawn Properties")
	class AActor* SpawnedItem;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Spawn Properties")
	float SpawnDelayMin;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Spawn Properties")
	float SpawnDelayMax;

	int RandSpawnDelay;
	int startingSysTime;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//should be called when the SpawnedItem is removed
	virtual void SetNextSpawn();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
