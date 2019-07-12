// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GlobalDefinitions.h"
#include "KID_Character.generated.h"

class AGridController;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCharacterDelegate);

UCLASS()
class KINDISDEAD_API AKID_Character : public ACharacter
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this character's properties
	AKID_Character();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

	FCharacterDelegate OnDeath;

	UFUNCTION(BlueprintCallable)
		void Fire(UPARAM(ref) AActor * Target);
	UFUNCTION(BlueprintPure, Category = "Health")
		float GetHealthPercent() const;

	UPROPERTY(BlueprintReadWrite)
		AGridController* GridReference;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
		ETeam Team = ETeam::None;
	UPROPERTY(BlueprintReadOnly, Category = "Setup")
		EAttackStatus AttackState = EAttackStatus::Reloading;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
		float ReloadTime = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
		float Attack = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
		int32 Armor = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	int32 StartingHealth = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
		int32 AttackRadius = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
		int32 Speed = 300;
private:
	UPROPERTY(VisibleAnywhere, Category = "Setup")
		int32 CurrentHealth;
	UFUNCTION(BlueprintCallable, Category = "Damage")
		int32 GetHealth();
	
	double LastFireTime = 0;
};
