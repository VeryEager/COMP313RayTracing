// Fill out your copyright notice in the Description page of Project Settings.


#include "EndOfLevelTrigger.h"
#include "Components/BoxComponent.h"
#include "FoxCharacter.h"
#include "Components/WidgetComponent.h"

// Sets default values
AEndOfLevelTrigger::AEndOfLevelTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//define visual components
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = StaticMesh;

	RequirementDisplay = CreateDefaultSubobject<UWidgetComponent>(TEXT("Requirements"));
	RequirementDisplay->SetupAttachment(RootComponent);

	//define interactive components
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->SetCollisionProfileName(TEXT("Trigger"));
	Trigger->SetupAttachment(RootComponent);
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AEndOfLevelTrigger::OnOverlapBegin);
	Trigger->OnComponentEndOverlap.AddDynamic(this, &AEndOfLevelTrigger::OnOverlapEnd);

	MinScoreRequired = 12;
	MaxScoreRequired = 2*MinScoreRequired;
}

// Called when the game starts or when spawned
void AEndOfLevelTrigger::BeginPlay()
{
	Super::BeginPlay();
	RandScore = FMath::RandRange(MinScoreRequired, MaxScoreRequired);
}

// Called every frame; deprecated
void AEndOfLevelTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AEndOfLevelTrigger::CheckPlayerConditions(AActor* Player) {
	return false;
}

void AEndOfLevelTrigger::OnOverlapBegin(UPrimitiveComponent* Overlapped, AActor* OtherActor, UPrimitiveComponent* OtherOverlapped, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if (OtherActor && (OtherActor != this) && OtherActor->IsA(AFoxCharacter::StaticClass())) {
		
		//check that the player has enough collectibles to finish the level
		CheckPlayerConditions(OtherActor);
	}
}

void AEndOfLevelTrigger::OnOverlapEnd(UPrimitiveComponent* Overlapped, AActor* OtherActor, UPrimitiveComponent* OtherOverlapped, int32 OtherBodyIndex) {

}

