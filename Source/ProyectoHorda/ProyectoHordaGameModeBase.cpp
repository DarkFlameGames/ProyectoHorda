// Copyright Epic Games, Inc. All Rights Reserved.


#include "ProyectoHordaGameModeBase.h"
#include "CharacterCore.h"
#include "Kismet/GameplayStatics.h"

AProyectoHordaGameModeBase::AProyectoHordaGameModeBase()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AProyectoHordaGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AProyectoHordaGameModeBase::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	playerDead();
}

void AProyectoHordaGameModeBase::playerDead() {
	
	ACharacterCore* character = Cast<ACharacterCore>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (character == NULL) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("AAAAAAAAAAA")));
		
	}
	else {
		if (character->currentHealth <= 0) {
			GetWorld()->ServerTravel("01");
		}
	}
	
}