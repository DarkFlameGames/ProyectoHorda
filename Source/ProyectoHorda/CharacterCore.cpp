// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterCore.h"
#include "GenericPlatform/GenericPlatformMath.h"
// Sets default values
ACharacterCore::ACharacterCore()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Evita que nuestro personaje rote, solo permite que la camara rote
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	//Rota adecuadamente el personaje a la direccion en que se esta moviendo
	GetCharacterMovement()->bOrientRotationToMovement = true;
	//Indica la velocidad y el eje sobre el cual rotara el personaje
	GetCharacterMovement()->RotationRate = FRotator(0, 500, 0);
	//Establece la velocidad a la cual vamos a saltar
	GetCharacterMovement()->JumpZVelocity = 600;
	//Establece que tanto vamos a controlar al personaje cuando se encuentra en el aire
	GetCharacterMovement()->AirControl = 0.2f;
	//Establece la velocidad del personaje
	

	//Definimos el componente de camara boon y los fijamos al componente raiz
	CameraBoon = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoon->SetupAttachment(RootComponent);

	//Distancia a la cual vamos a situar ese "palo de selfie" del personaje
	CameraBoon->TargetArmLength = 300.f;

	//Rota el "palo de selfie" basado en la posicion del personaje
	CameraBoon->bUsePawnControlRotation = true;

	//Crea la camara principal y la establece en el cameraboon
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoon, USpringArmComponent::SocketName);

	//Establece que la rotacion basado en el pawn es falso porque ya esto lo hace el camera boon
	FollowCamera->bUsePawnControlRotation = false;

}

// Called when the game starts or when spawned
void ACharacterCore::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACharacterCore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	totalVelocity = sqrt(pow(GetCharacterMovement()->Velocity.GetAbs().Y, 2) + pow(GetCharacterMovement()->Velocity.GetAbs().Z, 2) + pow(GetCharacterMovement()->Velocity.GetAbs().X, 2));
	
}

// Called to bind functionality to input
void ACharacterCore::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed,this,&ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	//PlayerInputComponent->BindAxis("Up", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAxis("Forward", this, &ACharacterCore::moveForward);
	PlayerInputComponent->BindAxis("Side", this, &ACharacterCore::moveSide);
}

void ACharacterCore::moveForward(float value)
{
	FRotator yawRotation(0.0f, Controller->GetControlRotation().Yaw, 0);

	FVector Direction = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);

	AddMovementInput(Direction, value);
}

void ACharacterCore::moveSide(float value)
{
	FRotator yawRotation(0.0f, Controller->GetControlRotation().Yaw, 0);

	FVector Direction = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);

	
	AddMovementInput(Direction, value);
}
