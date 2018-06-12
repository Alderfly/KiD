// Fill out your copyright notice in the Description page of Project Settings.

#include "UnitAIController.h"
#include "Unit.h"

void AUnitAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledUnit = GetControlledUnit();
	if (!ControlledUnit)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller not possessing unit"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller possessing: %s"), *(ControlledUnit->GetName()));
	}
}

void AUnitAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

AUnit* AUnitAIController::GetControlledUnit() const
{
	return Cast<AUnit>(GetPawn());
}

