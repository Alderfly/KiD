// Fill out your copyright notice in the Description page of Project Settings.

#include "GridController.h"
#include "Runtime/Engine/Public/EngineUtils.h"
#include "Components/StaticMeshComponent.h"
#include "Public/Tile.h"

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

	//for (int32 i = 0; i < sizeX; i++)
	//{
	//	for (int32 j = 0; j < sizeX; j++)
	for (auto& Actor : AllTiles)
	{
		auto Location = Actor->FindComponentByClass<UStaticMeshComponent>()->GetOwner()->GetActorLocation();
		UE_LOG(LogTemp, Warning, TEXT("Actor on pressure plate %s"), *Location.ToString())
	}
}

// Called every frame
void AGridController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

