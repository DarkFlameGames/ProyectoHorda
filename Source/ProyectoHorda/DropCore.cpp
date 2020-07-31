// Fill out your copyright notice in the Description page of Project Settings.


#include "DropCore.h"

// Sets default values
ADropCore::ADropCore()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void ADropCore::BeginPlay()
{
	Super::BeginPlay();
	delayToDelete = 10;
}

// Called every frame
void ADropCore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalRotation(FRotator(0,2,0));
	if (delayToDelete<=0) {
		Destroy();
	}
	delayToDelete -= DeltaTime;
}

