// Fill out your copyright notice in the Description page of Project Settings.

#include "UnitAIController.h"
#include "KID_Character.h"

void AUnitAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledCharacter = GetControlledCharacter();
	if (!ControlledCharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller not possessing unit"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller possessing: %s"), *(ControlledCharacter->GetName()));
	}
}

void AUnitAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

void AUnitAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedCharacter = Cast<AKID_Character>(InPawn);
		if (!ensure(PossessedCharacter)) { return; }

		PossessedCharacter->OnDeath.AddUniqueDynamic(this, &AUnitAIController::OnPossessedCharacterDeath);
	}
}

void AUnitAIController::OnPossessedCharacterDeath()
{
	//UE_LOG(LogTemp, Warning, TEXT("Unit Died"))
	if (!GetPawn()) { return; }
	GetPawn()->DetachFromControllerPendingDestroy();
}

AKID_Character* AUnitAIController::GetControlledCharacter() const
{
	return Cast<AKID_Character>(GetPawn());
}