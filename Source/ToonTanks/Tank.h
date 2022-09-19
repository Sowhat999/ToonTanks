// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();

	void HandleDestruction();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	APlayerController* GetTankPlayerController() const {return TankPlayerController;}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:
	// Components
	UPROPERTY(VisibleAnywhere, Category="Components")
	class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category="Components")
	class UCameraComponent* MainCamera;

	// Movement
	UPROPERTY(EditAnywhere, Category="Movement")
	float Speed {300.f};
	UPROPERTY(EditAnywhere, Category="Movement")
	float TurnRate {100.f};

	void Move(float Value);
	void Turn(float Value);

	APlayerController* TankPlayerController;
	
};
