// Fill out your copyright notice in the Description page of Project Settings.

#include "KID_Character.h"
#include "GridController.h"
#include "Runtime/Engine/Public/EngineUtils.h"

// Sets default values
AKID_Character::AKID_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AKID_Character::BeginPlay()
{
	Super::BeginPlay();
	
	LastFireTime = FPlatformTime::Seconds();
	CurrentHealth = StartingHealth;

	for (TActorIterator<AGridController> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (!ActorItr) { return; }
		else
		{
			GridReference = *ActorItr;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Grid %s "), *(GridReference->GetName()))
}

// Called every frame
void AKID_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AKID_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AKID_Character::Fire(UPARAM(ref)AActor * Target)
{

}

float AKID_Character::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);

	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
		Destroy();
	}

	return DamageToApply;
}

float AKID_Character::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}

int32 AKID_Character::GetHealth()
{
	return CurrentHealth;
}

