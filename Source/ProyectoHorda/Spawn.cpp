// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawn.h"
#include "ProyectoHordaGameModeBase.h"

// Sets default values
ASpawn::ASpawn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	delaySpawn = 0.2;
}

// Called when the game starts or when spawned
void ASpawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if ((DeltaTime >= timeLeft) && spawnEnable) {
		generateEnemy();
		modifyTotalEnemies(1);
		timeLeft = DeltaTime + delaySpawn;
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, FString::Printf(TEXT("time: %f"), timeLeft));
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, FString::Printf(TEXT("delta: %f"), DeltaTime));
	}
	timeLeft -= DeltaTime;
	totalEnemies();
}

void ASpawn::generateEnemy() {
	GetWorld()->SpawnActor<AActor>(enemy, this->GetActorLocation(), this->GetActorRotation());
}

void ASpawn::modifyTotalEnemies(float add) {
	AGameModeBase* gameMode = GetWorld()->GetAuthGameMode();
	AProyectoHordaGameModeBase* gameModeBase= Cast<AProyectoHordaGameModeBase>(gameMode);
	gameModeBase->currentEnemies += 1;
}

void ASpawn::totalEnemies() {
	AGameModeBase* gameMode = GetWorld()->GetAuthGameMode();
	AProyectoHordaGameModeBase* gameModeBase = Cast<AProyectoHordaGameModeBase>(gameMode);
	if (gameModeBase->currentEnemies < 200) {
		spawnEnable = true;
	}
	else {
		spawnEnable = false;
	}
}