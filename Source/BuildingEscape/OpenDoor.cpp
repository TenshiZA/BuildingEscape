// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UOpenDoor::OpenTheDoor(){

	//get the owner
	Owner = GetOwner();

	//create a new rotation
	FRotator MyCurrentRot = FRotator(0.0f,90.0f,0.0f);

	//update the rotation of the actor
	Owner->SetActorRotation(MyCurrentRot);


}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...	
	/*FRotator MyCurrentRot = Owner->GetActorRotation();
	if ( MyCurrentRot.Yaw < 150.0f ) { MyCurrentRot.Yaw += 1; }
	//update the rotation of the actor
	Owner->SetActorRotation(MyCurrentRot);*/


	//Poll the Trigger Volume
	if ( PressurePlate->IsOverlappingActor(ActorThatOpens)){
		//IF the ActorThatopens touches it Open the door
		UE_LOG(LogTemp,Warning, TEXT("Touching the door") );
		OpenTheDoor();

	}

	


}

