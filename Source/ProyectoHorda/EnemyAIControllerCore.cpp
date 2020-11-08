// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIControllerCore.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "CharacterCore.h"
#include "Kismet/GameplayStatics.h"




AEnemyAIControllerCore::AEnemyAIControllerCore() {
	
	PrimaryActorTick.bCanEverTick = true;

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));

	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));

	SightConfig->SightRadius = 484294499342745600.0f;
	SightConfig->LoseSightRadius = 0.0f;
	SightConfig->PeripheralVisionAngleDegrees = 180.0f;
	SightConfig->SetMaxAge(0.0f);

	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &AEnemyAIControllerCore::OnPawnDetected);
	GetPerceptionComponent()->ConfigureSense(*SightConfig);

}

void AEnemyAIControllerCore::BeginPlay() {
	
	Super::BeginPlay();

	
}

void AEnemyAIControllerCore::OnPossess(APawn* PawnA)
{
	Super::OnPossess(PawnA);

}

void AEnemyAIControllerCore::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
}

FRotator AEnemyAIControllerCore::GetControlRotation() const
{

	if (GetPawn() == nullptr) {
		return FRotator(0.0f, 0.0f, 0.0f);
	}
	return FRotator(0.0f,GetPawn()->GetActorRotation().Yaw,0.0f);
}

void AEnemyAIControllerCore::OnPawnDetected(const TArray<AActor*>& DetectedPawns)
{
}

void AEnemyAIControllerCore::FollowPlayerAI()
{

	if (!(character->IsValidLowLevelFast())) {
		character = Cast<ACharacterCore>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("AAAAAAAAAAA")));

	}

	if (!(enemy->IsValidLowLevelFast())) {
		enemy = GetPawn();
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("EEEEEEEEEE")));

	}
	

	float distanceFromCharacter = (character->GetActorLocation() - enemy->GetActorLocation()).Size();

	FAIMoveRequest MoveToCharacter;
	MoveToCharacter.SetUsePathfinding(true);
	MoveToCharacter.SetAcceptanceRadius(20.0f);
	MoveToCharacter.SetReachTestIncludesAgentRadius(false);

	if (character)
	{
		MoveToCharacter.SetGoalActor(character);
	}
	else
	{
		MoveToCharacter.SetGoalLocation(character->GetActorLocation());
	}


	MoveToCharacter.SetNavigationFilter(this->GetDefaultNavigationFilterClass());
	FPathFollowingRequestResult ResultData = this->MoveTo(MoveToCharacter);
	
}
