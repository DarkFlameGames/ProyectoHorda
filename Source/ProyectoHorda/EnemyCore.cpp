// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCore.h"
#include "ProyectoHordaGameModeBase.h"

// Sets default values
AEnemyCore::AEnemyCore()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	enemyHealth = 100;
}

// Called when the game starts or when spawned
void AEnemyCore::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->JumpZVelocity = 600;
	GetCharacterMovement()->AirControl = 0.4f;
}

// Called every frame
void AEnemyCore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (enemyHealth<=0) {
		scoreUpdate();
		int position = FMath::RandRange(0, 9);
		if (position == 0) {
			spawnDrops();
		}
		Destroy();
	}
}

// Called to bind functionality to input
void AEnemyCore::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyCore::enemyDamage(float damage)
{
	enemyHealth -= damage;
}

void AEnemyCore::scoreUpdate() {
	AGameModeBase* gameMode = GetWorld()->GetAuthGameMode();
	AProyectoHordaGameModeBase* gameModeBase = Cast<AProyectoHordaGameModeBase>(gameMode);
	gameModeBase->totalScore += givenScore;
}

void AEnemyCore::spawnDrops() {
	int position = FMath::RandRange(0, 2);
	GetWorld()->SpawnActor<AActor>(drops[position], this->GetActorLocation(), this->GetActorRotation());
}