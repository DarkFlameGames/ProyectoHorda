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
	
public:

	//Almacena los enemigos totales en la partida actualmente
	int currentEnemies;

};
