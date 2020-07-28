// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterGun.h"


void UCharacterGun::shoot()
{
	GetWorld()->SpawnActor<AActor>(ammo, this->GetComponentLocation(), this->GetComponentRotation());
}
