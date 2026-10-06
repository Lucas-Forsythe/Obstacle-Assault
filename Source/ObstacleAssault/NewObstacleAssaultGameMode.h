#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NewObstacleAssaultGameMode.generated.h"

UCLASS()
class OBSTACLEASSAULT_API ANewObstacleAssaultGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	ANewObstacleAssaultGameMode();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// Called when the player reaches the finish
	UFUNCTION(BlueprintCallable)
	void PlayerReachedFinish();

	// Called when the player touches the floor/failure area
	UFUNCTION(BlueprintCallable)
	void PlayerTouchedFloor();

private:

	// How long the player has been attempting the course
	float CourseTime = 0.0f;

	// Is the timer currently running?
	bool bCourseActive = false;

	// Has the player completed the course?
	bool bCourseCompleted = false;
};