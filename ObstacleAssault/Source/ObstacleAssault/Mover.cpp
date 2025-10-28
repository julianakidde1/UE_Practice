// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

	AActor* MyOwner = GetOwner(); //getOwner returns a pointer 
	StartLocation = MyOwner->GetActorLocation(); //or StartLocation = GetOwner()->GetActorLocation(); 

	
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (ShouldMove)
	{
		TargetLocation = StartLocation + MoveOffset; 
	}
	else
	{
		TargetLocation = StartLocation;

	}

	FVector CurrentLocation = GetOwner()->GetActorLocation(); 

	ReachedTarget = CurrentLocation.Equals(TargetLocation); //checks if the Current location equals the targetLocation
	  
	if (!ReachedTarget) //move is only executed while the door is yet to reach the target
	{
		float Speed = MoveOffset.Length() / MoveTime; //since moveOffset is an FVector 
	
		FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed); // special function calculates the updated location per frame? 

		GetOwner()->SetActorLocation(NewLocation);
	}

	
}

