// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

UENUM(BlueprintType)
enum class ETileType: uint8
{
	Empty,
	Ground
};

UCLASS()
class KINDISDEAD_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UPROPERTY(EditAnywhere, Instanced, Category = "Components")
	//UStaticMeshComponent * TileMesh = nullptr;

	//UPROPERTY(EditAnywhere, Category = "Components")
	//UStaticMeshComponent * CollisionMesh = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Setup)
	ETileType TileType = ETileType::Empty;
};
