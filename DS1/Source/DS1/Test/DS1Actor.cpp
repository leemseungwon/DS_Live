// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/DS1Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADS1Actor::ADS1Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	SetRootComponent(Body);

	if (Body)
	{
		ConstructorHelpers::FObjectFinder<UStaticMesh> BodyRef(TEXT(
			"/Script/Engine.StaticMesh'/Game/LevelPrototyping/Interactable/Target/Assets/SM_TargetBaseMesh.SM_TargetBaseMesh'"));
		if (BodyRef.Succeeded())
		{
			Body->SetStaticMesh(BodyRef.Object);

		}
	}
}

// Called when the game starts or when spawned
void ADS1Actor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADS1Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float Distance = DeltaTime * 50.0f;

	// FVector Location = GetActorLocation();
	// FVector NewLocation = Location + FVector::ForwardVector * Distance;
	// SetActorLocation(NewLocation);	

	// AddActorWorldOffset(FVector::ForwardVector * Distance);

	//float RollRotate = DeltaTime * 45.0f;
	// FRotator Rotation = GetActorRotation();
	// FRotator NewRotation = FRotator(Rotation.Pitch, Rotation.Yaw,
	// 	   Rotation.Roll + RollRotate);
	// SetActorRotation(NewRotation);

	// AddActorWorldRotation(FRotator(0.0f, 0.0f, RollRotate));

	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("Target"), OUT Actors);

	if (Actors.Num() > 0)
	{
		TargetActor = Actors[0];
	}

	if (TargetActor)
	{
		FVector Direction = TargetActor->GetActorLocation() - GetActorLocation();
		Direction.Normalize();
		AddActorWorldOffset(Direction * Distance);
	}
}

