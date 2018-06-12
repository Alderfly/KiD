// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridController.generated.h"

class ATile;
class AUnit;

UCLASS()
class KINDISDEAD_API AGridController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void SetUnitArrays();
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 sizeX;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 sizeY;

	TArray<ATile*> AllTiles;
	TArray<AUnit*> PlayerUnits;
	TArray<AUnit*> EnemyUnits;
};
