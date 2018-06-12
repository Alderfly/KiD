// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "UnitAIController.generated.h"

class AUnit;
/**
 * 
 */
UCLASS()
class KINDISDEAD_API AUnitAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	// Called when the game starts or when spawned
	void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	AUnit * GetControlledUnit() const;

};
