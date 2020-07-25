// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawn.generated.h"

UCLASS()
class PROYECTOHORDA_API ASpawn : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawn();
	float delaySpawn;
	float timeLeft;
	bool spawnEnable;
	
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AActor> enemy;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void generateEnemy();
	void modifyTotalEnemies(float number);
	void totalEnemies();
};
