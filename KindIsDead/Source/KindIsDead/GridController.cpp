// Fill out your copyright notice in the Description page of Project Settings.

#include "GridController.h"
#include "Runtime/Engine/Public/EngineUtils.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Public/Tile.h"
#include "Public/Unit.h"

// Sets default values
AGridController::AGridController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AGridController::SetUnitArrays()
{
	for (TActorIterator<AUnit> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr->Team == ETeam::Player) 
		{
			PlayerUnits.Push(*ActorItr);
		}
		else
		{
			EnemyUnits.Push(*ActorItr);
		}
	}

	for (auto& Actor : PlayerUnits)
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

	SetUnitArrays();
}

// Called every frame
void AGridController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

