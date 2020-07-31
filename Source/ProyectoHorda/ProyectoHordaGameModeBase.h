// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ProyectoHordaGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PROYECTOHORDA_API AProyectoHordaGameModeBase : public AGameModeBase
{
	GENERATED_BODY()	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	AProyectoHordaGameModeBase();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	int currentEnemies;
	
	UPROPERTY(VisibleAnywhere)
	float totalScore;

	void playerDead();
};
