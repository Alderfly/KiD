// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GlobalDefinitions.h"
#include "Building.generated.h"

UCLASS()
class KINDISDEAD_API ABuilding : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilding();
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;
	UFUNCTION(BlueprintCallable, Category = "Damage")
	int32 GetHealth();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Setup)
	ETeam Team = ETeam::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	int32 Armor = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	int32 StartingHealth = 1600;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	int32 AttackRadius = 700;

private:

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	int32 CurrentHealth;
};
