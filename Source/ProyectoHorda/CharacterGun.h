// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "CharacterGun.generated.h"

/**
 * 
 */
UCLASS()
class PROYECTOHORDA_API UCharacterGun : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AActor> ammo;
	void shoot();
};
