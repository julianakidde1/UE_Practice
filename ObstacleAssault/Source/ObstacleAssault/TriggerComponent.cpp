// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
    PrimaryComponentTick.bCanEverTick = true; 
}

void UTriggerComponent::BeginPlay()
{
    Super::BeginPlay();

    if (MoverActor != nullptr)
    {
        Mover = MoverActor->FindComponentByClass<UMover>(); //it will look for a "UMover component" within the "MoverActor"
        if (Mover != nullptr) 
        {

        }

        else
        {
            UE_LOG (LogTemp, Display, TEXT("Failed to find mover component."));
        }
        
    }

    else
    {
        UE_LOG (LogTemp, Display, TEXT("Mover actor is nullptr"));
    }
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
