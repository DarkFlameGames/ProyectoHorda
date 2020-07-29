// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "CharacterGun.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "CharacterCore.generated.h"


UCLASS()
class PROYECTOHORDA_API ACharacterCore : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterCore();
	//Almacena la velocidad normal de caminata del jugador
	float oldMaxSpeed;
	//Almacena la vida actual del jugador principal
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float currentHealth;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float maxHealth;
	//Permite visualizar y almacenar la velocidad total del jugador
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
		float totalVelocity;
	//Funciona como un palo de selfie, es una camara que te sigue y detecta las colisiones y se acerca a ti
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		USpringArmComponent* CameraBoon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gun)
		UCharacterGun* Gun;

	//Componente basico de la camara que seguira al personaje
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		UCameraComponent* FollowCamera;

	//Movimientos adelante,atras Izquierda y derecha
	void moveForward(float value);
	void moveSide(float value);
	void startRun();
	void stopRun();
	void characterRotation(float value);
	void startShooting();

	UFUNCTION(BlueprintCallable)
	void reduceHealth(float damage);
	UFUNCTION(BlueprintCallable)
		void setGun(UCharacterGun* GunObject);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};