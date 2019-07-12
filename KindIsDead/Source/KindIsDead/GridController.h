// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridController.generated.h"

class ATile;
class AUnit;
class ABuilding;
class AKID_Character;

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
	void SetAllArrays();
	void SetPlayerBuildings();
	void SetTeam1Buildings();
	void SetPlayerCharacters();
	void SetTeam1Characters();
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable, Category = "Game Arrays")
	void GetEnemyBuildings(UPARAM(ref) ETeam MyTeam, TArray<ABuilding*> &EnemyBuildings);

	UFUNCTION(BlueprintCallable, Category = "Game Arrays")
	void GetAllArrays(TArray<ABuilding*> &PlayerBs, TArray<ABuilding*> &Team1Bs, TArray<AKID_Character*> &PlayerChs, TArray<AKID_Character*> &Team1Chs);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 sizeX;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 sizeY;

	TArray<ATile*> AllTiles;
	TArray<AKID_Character*> PlayerCharacters;
	TArray<AKID_Character*> Team1Characters;
	TArray<ABuilding*> PlayerBuildings;
	TArray<ABuilding*> Team1Buildings;

};
