// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

#include "Kismet/GameplayStatics.h"

void ATower::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// find distance to the tank
	if (Tank)
	{
		// check to see if the tank is in range
		if (TankIsInRange())
		{
			// if in range, rotate turret
			RotateTurret(Tank->GetActorLocation());
		}
	}
}

void ATower::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

void ATower::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FireRate, true);
}

void ATower::CheckFireCondition()
{
	if (Tank == nullptr)
	{
		return;
	}
	if (TankIsInRange() && Tank->bAlive)
	{
		Fire();
	}
}

bool ATower::TankIsInRange() const
{
	if (Tank)
	{
		return FVector::Dist(GetActorLocation(), Tank->GetActorLocation()) <= FireRange;
	}

	return false;
}
