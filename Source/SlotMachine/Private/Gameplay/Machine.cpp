// Fill out your copyright notice in the Description page of Project Settings.


#include "Machine.h"

// Sets default values
AMachine::AMachine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Box = CreateDefaultSubobject<UStaticMeshComponent>("Box");
	RootComponent = Box;
	Lever = CreateDefaultSubobject<UStaticMeshComponent>("Lever");
	Lever->AttachToComponent(Box, FAttachmentTransformRules::KeepRelativeTransform);
	ReelLeft = CreateDefaultSubobject<UStaticMeshComponent>("ReelLeft");
	ReelLeft->AttachToComponent(Box, FAttachmentTransformRules::KeepRelativeTransform);
	ReelCenter = CreateDefaultSubobject<UStaticMeshComponent>("ReelCenter");
	ReelCenter->AttachToComponent(Box, FAttachmentTransformRules::KeepRelativeTransform);
	ReelRight = CreateDefaultSubobject<UStaticMeshComponent>("ReelRight");
	ReelRight->AttachToComponent(Box, FAttachmentTransformRules::KeepRelativeTransform);
	Light = CreateDefaultSubobject<UStaticMeshComponent>("Light");
	Light->AttachToComponent(Box, FAttachmentTransformRules::KeepRelativeTransform);
	
}

// Called when the game starts or when spawned
void AMachine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

