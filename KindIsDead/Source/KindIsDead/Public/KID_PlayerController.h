// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "KID_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class KINDISDEAD_API AKID_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	// Called when the game starts or when spawned
	void BeginPlay() override;	
	
};
