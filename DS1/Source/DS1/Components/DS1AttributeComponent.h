// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DS1Define.h"
#include "Components/ActorComponent.h"
#include "DS1AttributeComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FDelegateOnAttributeChanged, EDS1AttributeType, float)

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DS1_API UDS1AttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UDS1AttributeComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	FORCEINLINE float GetBaseStamina() const { return BaseStamina; }
	FORCEINLINE float GetMaxStamina() const { return MaxStamina; }

	bool CheckHasEnoughStamina(float StaminaCost) const;

	void DecreaseStamina(float StaminaCost);

	void ToggleStaminaRegeneration(bool bEnabled, float StartDelay = 2.0f);

	void RegenerateStamina();

	void BroadcastAttributeChanged(EDS1AttributeType InAttributeType) const;

public:
	FDelegateOnAttributeChanged OnAttributeChanged;

protected:
	UPROPERTY(EditAnywhere, Category = Attribute)
	float BaseStamina = 100.0f;

	UPROPERTY(EditAnywhere, Category = Attribute)
	float MaxStamina = 100.0f;

	UPROPERTY(EditAnywhere, Category = Attribute)
	float StaminaRegenRate = 0.2f;

	FTimerHandle StaminaRegenTimerHandle;
};
