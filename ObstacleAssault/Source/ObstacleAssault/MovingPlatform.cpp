// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{

	DistanceMoved = GetDistanceMoved();

	if (DistanceMoved >= MoveDistance)
	{
		float Overshoot = MoveDistance - DistanceMoved;

		FVector MoveDirection = PlatformVelocity.GetSafeNormal(); 
		FVector NewStartLocation = StartLocation + MoveDirection * MoveDistance; // to avoid overshoot problem, and account for when it moves more than the desired amount (use this instead of setting SL to CurrentLocation)
		SetActorLocation (NewStartLocation);
		StartLocation = NewStartLocation; 

		PlatformVelocity = -PlatformVelocity; 

	}

	else
	{
		FVector CurrentLocation = GetActorLocation(); 
		
		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime); // makes it so it moves at the same rate w/ every computer ie "100cm/sec"
		
		SetActorLocation(CurrentLocation);
	}

}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	//rotates platform
	FRotator RotationToAdd = RotationVelocity * DeltaTime; //multiply by deltaTime to make it framerate independent. 
	AddActorLocalRotation(RotationToAdd); 
}

float AMovingPlatform::GetDistanceMoved()
{
	
    return FVector::Dist(StartLocation, GetActorLocation()); //start location is set w/ begin play. distMoved is updated w/ tick 
}


