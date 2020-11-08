// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawn.h"
#include "ProyectoHordaGameModeBase.h"

// Sets default values
ASpawn::ASpawn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Establece cuanto tiempo esperar antes de generar otro enemigo
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

	//Establece un timer para el spawn de enemigos, comprobando el tiempo de respawn y si el spawn esta activo
	if ((DeltaTime >= timeLeft) && spawnEnable) {
		generateEnemy();
		modifyTotalEnemies();
		timeLeft = DeltaTime + delaySpawn;
		
	}
	timeLeft -= DeltaTime;
	totalEnemies();

}

//Metodo que permite la generacion de enemigos en el lugar y con la rotacion del objeto
void ASpawn::generateEnemy() {

	GetWorld()->SpawnActor<AActor>(enemy, this->GetActorLocation(), this->GetActorRotation());

}

//Almacena en el modo de juego el total de enemigos generados
void ASpawn::modifyTotalEnemies() {

	AGameModeBase* gameMode = GetWorld()->GetAuthGameMode();

	AProyectoHordaGameModeBase* gameModeBase= Cast<AProyectoHordaGameModeBase>(gameMode);

	gameModeBase->currentEnemies += 1;

}

//Obtiene y lleva un control de los enemigos generados para generar un tope de enemigos 
void ASpawn::totalEnemies() {

	AGameModeBase* gameMode = GetWorld()->GetAuthGameMode();

	AProyectoHordaGameModeBase* gameModeBase = Cast<AProyectoHordaGameModeBase>(gameMode);

	if (gameModeBase->currentEnemies < enemyAmount) {
		spawnEnable = true;
	}
	else {
		spawnEnable = false;
	}

}