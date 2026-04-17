// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "DS1Equipment.generated.h"

UCLASS()
class DS1_API ADS1Equipment : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADS1Equipment();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	FORCEINLINE UStaticMesh* GetMeshAsset() { return MeshAsset; }

public:
	virtual void EquipItem();
	virtual void UnEquipItem();
	virtual void AttachToOwner(FName SocketName)
	{
		ACharacter* OwnerCharacter = Cast<ACharacter>(GetOwner());

		if (OwnerCharacter)
		{
			USkeletalMeshComponent* CharacterMesh = OwnerCharacter->GetMesh();
			if (CharacterMesh)
			{
				AttachToComponent(CharacterMesh, FAttachmentTransformRules(
					EAttachmentRule::SnapToTarget, true), SocketName);
			}
		}
	}

protected:
	UPROPERTY(VisibleAnywhere, Category = "Equipment | Mesh")
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(EditAnywhere, Category = "Equipment | Mesh")
	TObjectPtr<UStaticMesh> MeshAsset;
};
