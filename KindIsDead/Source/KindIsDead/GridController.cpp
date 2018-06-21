// Fill out your copyright notice in the Description page of Project Settings.

#include "GridController.h"
#include "Runtime/Engine/Public/EngineUtils.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Public/Tile.h"
#include "Public/KID_Character.h"
#include "Public/Building.h"

// Sets default values
AGridController::AGridController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGridController::BeginPlay()
{
	Super::BeginPlay();

	for (TActorIterator<ATile> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AllTiles.Push(*ActorItr);
	}

	//for (auto& Actor : AllTiles)
	//{
	//	auto Location = Actor->FindComponentByClass<UStaticMeshComponent>()->GetOwner()->GetActorLocation();
	//	UE_LOG(LogTemp, Warning, TEXT("Tile %s at %s"), *(Actor->GetName()), *Location.ToString())
	//}

	SetAllArrays();
}

// Called every frame
void AGridController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGridController::GetEnemyBuildings(UPARAM(ref) ETeam MyTeam, TArray<ABuilding*> &EnemyBuildings)
{
	if (MyTeam == ETeam::Player)
	{
		EnemyBuildings = PlayerBuildings;
	}
	else
	{
		EnemyBuildings = Team1Buildings;
	}
}

void AGridController::SetAllArrays()
{
	for (TActorIterator<AKID_Character> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr->Team == ETeam::Player)
		{
			PlayerCharacters.Push(*ActorItr);
		}
		else
		{
			Team1Characters.Push(*ActorItr);
		}
	}

	for (TActorIterator<ABuilding> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr->Team == ETeam::Player)
		{
			PlayerBuildings.Push(*ActorItr);
		}
		else
		{
			Team1Buildings.Push(*ActorItr);
		}
	}

	for (auto& Actor : PlayerCharacters)
	{
		auto Location = Actor->FindComponentByClass<USkeletalMeshComponent>()->GetOwner()->GetActorLocation();
		//UE_LOG(LogTemp, Warning, TEXT("Unit %s at %s"), *(Actor->GetName()), *Location.ToString())
	}

	//for (auto& Actor : EnemyUnits)
	//{
	//	auto Location = Actor->FindComponentByClass<UStaticMeshComponent>()->GetOwner()->GetActorLocation();
	//	UE_LOG(LogTemp, Warning, TEXT("Unit %s at %s"), *(Actor->GetName()), *Location.ToString())
	//}
}

void AGridController::SetPlayerBuildings()
{
	for (TActorIterator<ABuilding> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr->Team == ETeam::Player)
		{
			PlayerBuildings.Push(*ActorItr);
		}
	}
}

void AGridController::SetTeam1Buildings()
{
	for (TActorIterator<ABuilding> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr->Team == ETeam::Team1)
		{
			Team1Buildings.Push(*ActorItr);
		}
	}
}

void AGridController::SetPlayerCharacters()
{
	for (TActorIterator<AKID_Character> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr->Team == ETeam::Player)
		{
			PlayerCharacters.Push(*ActorItr);
		}
	}
}

void AGridController::SetTeam1Characters()
{
	for (TActorIterator<AKID_Character> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr->Team == ETeam::Team1)
		{
			Team1Characters.Push(*ActorItr);
		}
	}
}


