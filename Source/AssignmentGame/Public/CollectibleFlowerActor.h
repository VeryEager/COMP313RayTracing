// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollectibleFlowerActor.generated.h"

UCLASS()
class ASSIGNMENTGAME_API ACollectibleFlowerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectibleFlowerActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Scoring")
	int AccumulatedScore;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Visuals")
	class UStaticMeshComponent* StaticComponent;
	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
