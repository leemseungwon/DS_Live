// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DS1Character.generated.h"

struct FInputActionValue;

UCLASS()
class DS1_API ADS1Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADS1Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyControllerChanged() override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	bool IsMoving() const;

protected:
	UPROPERTY(EditAnywhere, Category = Sprinting)
	float SprintingSpeed = 750.0f;

	UPROPERTY(EditAnywhere, Category = Sprinting)
	float NormalSpeed = 500.0f;

	UPROPERTY(EditAnywhere, Category = Sprinting)
	float UseStamina = 5.0f;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UCameraComponent> Camera;

protected:
	UPROPERTY(EditAnywhere, Category = Montage)
	TObjectPtr<class UAnimMontage> RollingMontage;

public:
	bool bMovementInputEnabled = true;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UDS1AttributeComponent> AttributeComponent;

protected:
	UPROPERTY(EditAnywhere, Category = UI)
	TSubclassOf<UUserWidget> PlayerHUDWidgetClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UDS1PlayerHUDWidget> PlayerHUDWidget;

#pragma region InputSystem
public:
	void Input_Move(const FInputActionValue& InputValue);
	void Input_Look(const FInputActionValue& InputValue);

	void Sprinting();
	void StopSprint();
	void Rolling();

protected:
	UPROPERTY(EditAnywhere, Category = InputSystem)
	TObjectPtr<class UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditAnywhere, Category = InputSystem)
	TObjectPtr<class UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = InputSystem)
	TObjectPtr<class UInputAction> LookAction;

	UPROPERTY(EditAnywhere, Category = InputSystem)
	TObjectPtr<class UInputAction> SprintRollingAction;

#pragma endregion
};
