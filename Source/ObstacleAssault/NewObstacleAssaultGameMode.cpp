#include "NewObstacleAssaultGameMode.h"

ANewObstacleAssaultGameMode::ANewObstacleAssaultGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ANewObstacleAssaultGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Start the timer
	CourseTime = 0.0f;
	bCourseActive = true;
	bCourseCompleted = false;

	UE_LOG(LogTemp, Warning,
		TEXT("Obstacle course started!"));
}

void ANewObstacleAssaultGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Increase the timer while the player is attempting the course
	if (bCourseActive && !bCourseCompleted)
	{
		CourseTime += DeltaTime;
	}
}

void ANewObstacleAssaultGameMode::PlayerReachedFinish()
{
	// Don't complete the course more than once
	if (bCourseCompleted)
	{
		return;
	}

	bCourseCompleted = true;
	bCourseActive = false;

	UE_LOG(LogTemp, Warning,
		TEXT("COURSE COMPLETE! Time: %.2f seconds"),
		CourseTime);
}

void ANewObstacleAssaultGameMode::PlayerTouchedFloor()
{
	// Reset the timer
	CourseTime = 0.0f;

	// Start the course again
	bCourseActive = true;
	bCourseCompleted = false;

	UE_LOG(LogTemp, Warning,
		TEXT("PLAYER FAILED! Player touched the floor. Timer reset to 0."));
}