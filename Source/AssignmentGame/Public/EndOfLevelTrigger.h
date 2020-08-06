// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EndOfLevelTrigger.generated.h"

UCLASS()
class ASSIGNMENTGAME_API AEndOfLevelTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEndOfLevelTrigger();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
	class UBoxComponent* Trigger;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
	class UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
	class UWidgetComponent* RequirementDisplay;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Audio")
	class UAudioComponent* AudioComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Scoring")
	int MinScoreRequired;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Scoring")
	int MaxScoreRequired;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Scoring")
	int RandScore;

	TSubclassOf<UUserWidget> ELWRClass;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual bool CheckPlayerConditions(AActor* Player);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* Overlapped, AActor* OtherActor, UPrimitiveComponent* OtherOverlapped, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* Overlapped, AActor* OtherActor, UPrimitiveComponent* OtherOverlapped, int32 OtherBodyIndex);
};
