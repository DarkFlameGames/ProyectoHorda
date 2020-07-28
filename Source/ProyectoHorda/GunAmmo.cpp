// Fill out your copyright notice in the Description page of Project Settings.


#include "GunAmmo.h"

// Sets default values
AGunAmmo::AGunAmmo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	timeUntilDestroy = 10.f;
}

// Called when the game starts or when spawned
void AGunAmmo::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGunAmmo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (lifeTime >= timeUntilDestroy) {
		this->Destroy();
	}
	moveToEnemy();
	lifeTime += DeltaTime;
}

void AGunAmmo::moveToEnemy() {
	AddActorLocalOffset(FVector(20,0,0));
}

