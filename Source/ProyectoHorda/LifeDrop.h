// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DropCore.h"
#include "LifeDrop.generated.h"

/**
 * 
 */
UCLASS()
class PROYECTOHORDA_API ALifeDrop : public ADropCore
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALifeDrop();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
