# Obstacle-Assault
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
