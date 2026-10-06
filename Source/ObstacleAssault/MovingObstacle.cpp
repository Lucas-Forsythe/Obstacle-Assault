#include "MovingObstacle.h"
#include "Components/StaticMeshComponent.h"

AMovingObstacle::AMovingObstacle()
{
	PrimaryActorTick.bCanEverTick = true;

	ObstacleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObstacleMesh"));
	RootComponent = ObstacleMesh;

	ObstacleMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	ObstacleMesh->SetCollisionProfileName(TEXT("BlockAll"));
}

void AMovingObstacle::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	UE_LOG(LogTemp, Warning, TEXT("MovingObstacle initialized at %s"),
		*StartLocation.ToString());

	if (MovementOffset.IsNearlyZero())
	{
		UE_LOG(LogTemp, Warning,
			TEXT("MovingObstacle has zero MovementOffset. It will remain stationary."));
	}
}

void AMovingObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Movement
	if (!MovementOffset.IsNearlyZero())
	{
		// If we are currently paused, count down the pause timer
		if (PauseTimer > 0.0f)
		{
			PauseTimer -= DeltaTime;
		}
		else
		{
			float MovementDistance = MovementSpeed * DeltaTime;

			MovementProgress += MovementDistance * MovementDirection;

			// Reached the far endpoint
			if (MovementProgress >= 1.0f)
			{
				MovementProgress = 1.0f;
				MovementDirection = -1.0f;

				// Start endpoint pause
				PauseTimer = EndpointPauseTime;
			}
			// Reached the starting endpoint
			else if (MovementProgress <= 0.0f)
			{
				MovementProgress = 0.0f;
				MovementDirection = 1.0f;

				// Start endpoint pause
				PauseTimer = EndpointPauseTime;
			}
		}

		FVector NewLocation =
			StartLocation + (MovementOffset * MovementProgress);

		SetActorLocation(NewLocation);
	}

	// Rotation
	AddActorLocalRotation(RotationRate * DeltaTime);
}