// Fill out your copyright notice in the Description page of Project Settings.


#include "FoxCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/InputComponent.h"

// Sets default values
AFoxCharacter::AFoxCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);
	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);

	BaseTurnRate = 60.0f;
	BaseLookUpAtRate = 60.0f;

	//Collectible defaults
	playerCollectibles = 0;

	// Stamina defaults
	maxStamina = 100.0f;
	currentStamina = maxStamina;
	staminaDrain = 1.0f;
	staminaGain = 0.75f;
}

// Called when the game starts or when spawned
void AFoxCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void AFoxCharacter::MovementForward(float dist)
{
	if ((Controller) && dist != 0.0f) {
		const FRotator YawRotation(0, Controller->GetControlRotation().Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, dist);
	}
}

void AFoxCharacter::MoveRight(float val)
{
	if ((Controller) && val != 0.0f) {
		const FRotator YawRotation(0, Controller->GetControlRotation().Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, val);
	}
}

void AFoxCharacter::TurnAtRate(float val)
{
	AddControllerYawInput(val * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}


void AFoxCharacter::LookUpAtRate(float val)
{
	AddControllerPitchInput(val * BaseLookUpAtRate * GetWorld()->GetDeltaSeconds());
}

// Called to bind functionality to input
void AFoxCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released , this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AFoxCharacter::MovementForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFoxCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAxis("TurnRate", this, &AFoxCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AFoxCharacter::LookUpAtRate);
}

