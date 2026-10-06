#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FailureTrigger.generated.h"

class UBoxComponent;

UCLASS()
class OBSTACLEASSAULT_API AFailureTrigger : public AActor
{
	GENERATED_BODY()

public:

	AFailureTrigger();

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* TriggerBox;

	UFUNCTION()
	void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
};