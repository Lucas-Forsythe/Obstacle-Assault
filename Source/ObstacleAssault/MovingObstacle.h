#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingObstacle.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingObstacle : public AActor
{
    GENERATED_BODY()

public:
    AMovingObstacle();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* ObstacleMesh;

    FVector StartLocation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement",
        meta = (AllowPrivateAccess = "true"))
    FVector MovementOffset = FVector(500.0f, 0.0f, 0.0f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement",
        meta = (AllowPrivateAccess = "true"))
    float MovementSpeed = 200.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement",
        meta = (AllowPrivateAccess = "true"))
    FRotator RotationRate = FRotator(0.0f, 0.0f, 0.0f);

    // NEW: How long the obstacle waits at each endpoint
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement",
        meta = (AllowPrivateAccess = "true"))
    float EndpointPauseTime = 1.0f;

    float MovementProgress = 0.0f;

    float MovementDirection = 1.0f;

    // NEW: Tracks how long the obstacle has been paused
    float PauseTimer = 0.0f;
};