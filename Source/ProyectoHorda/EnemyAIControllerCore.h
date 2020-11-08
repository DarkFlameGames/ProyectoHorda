// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CharacterCore.h"
#include "EnemyAIControllerCore.generated.h"

/**
 * 
 */
UCLASS()
class PROYECTOHORDA_API AEnemyAIControllerCore : public AAIController
{
	GENERATED_BODY()


	AEnemyAIControllerCore();

	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* PawnA) override;

	virtual void Tick(float DeltaSeconds) override;

	virtual FRotator GetControlRotation() const override;


	float distanceToReFollow = 30.0f;

	ACharacterCore* character;
	APawn* enemy;

	UFUNCTION()

	void OnPawnDetected(const TArray<AActor*> &DetectedPawns);

	UFUNCTION(BlueprintCallable)

	void FollowPlayerAI();

	
	class UAISenseConfig_Sight* SightConfig;

	
};
