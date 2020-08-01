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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
	class USkeletalMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Visuals")
	int playerCollectibles;

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

};
