#include "FinishTrigger.h"

#include "Components/BoxComponent.h"
#include "NewObstacleAssaultGameMode.h"
#include "GameFramework/Character.h"

AFinishTrigger::AFinishTrigger()
{
	PrimaryActorTick.bCanEverTick = false;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));

	RootComponent = TriggerBox;

	TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TriggerBox->SetCollisionResponseToAllChannels(ECR_Overlap);
	TriggerBox->SetGenerateOverlapEvents(true);
}

void AFinishTrigger::BeginPlay()
{
	Super::BeginPlay();

	TriggerBox->OnComponentBeginOverlap.AddDynamic(
		this,
		&AFinishTrigger::OnOverlapBegin
	);
}

void AFinishTrigger::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	// Only react to the player
	if (!OtherActor || !OtherActor->IsA(ACharacter::StaticClass()))
	{
		return;
	}

	ANewObstacleAssaultGameMode* GameMode =
		Cast<ANewObstacleAssaultGameMode>(
			GetWorld()->GetAuthGameMode());

	if (GameMode)
	{
		GameMode->PlayerReachedFinish();
	}
}