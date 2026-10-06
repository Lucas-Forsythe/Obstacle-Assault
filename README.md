# Obstacle-Assault
# Lab 04 - Obstacle Course Gameplay Integration

## New Behavior
Some objects now have a timer that stops movement once they reach their end point

## custom GameMode rule
NewObstacleAssaultGameMode - Starts a timer when the game begins, displays timer when player reaches a finish point.

## Failure and Completion Flow
Failure trigger on the floor will reset the timer for the player when tey fall off the course, finish triggeer is located at the end of the course to end the timer before it is printed

## Independent Architecture Improvement

The obstacle and course systems were improved by separating reusable gameplay logic from level-specific configuration.

# Lab 03 - Moving Obstacle System

## C++ class
MovingObstacle C++ Actor

## Exposed properties
- Movement Offset
- Movement Speed
- Rotation Rate

## Blueprint child variants
- BP_MovingObstacle
- BP_MovingObstacle_Rotating
- BP_MovingObstacle_Vertical

## How DeltaTime is used
The obstacle uses DeltaTime in Tick() so movement and rotation are frame-rate independent.
