// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FoxCharacter.generated.h"

UCLASS()
class ASSIGNMENTGAME_API AFoxCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFoxCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Visuals")
	class USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Visuals")
	class UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Visuals")
	class USkeletalMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, Category = "Trigger")
	class UCapsuleComponent* Trigger;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Audio")
	class UAudioComponent* AudioComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player Data")
	float currentStamina;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player Data")
	float maxStamina;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player Data")
	float staminaDrain;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player Data")
	float staminaGain;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Data")
	int CurrentCollectibles;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MovementForward(float dist);
	void MoveRight(float val);
	void TurnAtRate(float val);
	void LookUpAtRate(float val);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Visuals")
	float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Visuals")
	float BaseLookUpAtRate;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* Overlapped, AActor* OtherActor, UPrimitiveComponent* OtherOverlapped, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* Overlapped, AActor* OtherActor, UPrimitiveComponent* OtherOverlapped, int32 OtherBodyIndex);
};
