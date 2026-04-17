// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Equipments/DS1Equipment.h"
#include "DS1Weapon.generated.h"

/**
 * 
 */
UCLASS()
class DS1_API ADS1Weapon : public ADS1Equipment
{
	GENERATED_BODY()

public:
	ADS1Weapon();

public:
	virtual void EquipItem() override;

public:
	FORCEINLINE FName GetEquipSocketName() const { return EquipSocketName; }
	FORCEINLINE FName GetUnEquipSocketName() const { return UnEquipSocketName; }

	FORCEINLINE UAnimMontage* GetEquipMontage() const { return EquipMontageAnimation; }
	FORCEINLINE UAnimMontage* GetUnEquipMontage() const { return UnEquipMontageAnimation; }

public:

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment | Socket")
	FName EquipSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment | Socket")
	FName UnEquipSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment | Animation")
	TObjectPtr<class UAnimMontage> EquipMontageAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment | Animation")
	TObjectPtr<class UAnimMontage> UnEquipMontageAnimation;

protected:
	UPROPERTY()
	TObjectPtr<class UDS1CombatComponent> CombatComponent;
};
