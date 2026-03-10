// Fill out your copyright notice in the Description page of Project Settings.

#include "Test/TestSpawner.h"
#include "Test/DS1Actor.h"

// Sets default values
ATestSpawner::ATestSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	FVector Location(0.0f, 0.0f, 0.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	DSActor = GetWorld()->SpawnActor<ADS1Actor>(Location, Rotation);

	DSActor->SetLifeSpan(5.0f);

	// GetWorld()->DestroyActor(DSActor);
}

// Called every frame
void ATestSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

