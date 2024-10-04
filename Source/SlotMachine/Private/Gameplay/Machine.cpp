// Fill out your copyright notice in the Description page of Project Settings.


#include "Machine.h"

// Sets default values
AMachine::AMachine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Box = CreateDefaultSubobject<UStaticMeshComponent>("Box");
	RootComponent = Box;
	LeverBase = CreateDefaultSubobject<USceneComponent>("LeverBase");
	LeverBase->AttachToComponent(Box, FAttachmentTransformRules::KeepRelativeTransform);
	LeverHandle = CreateDefaultSubobject<UStaticMeshComponent>("LeverHandle");
	LeverHandle->AttachToComponent(LeverBase, FAttachmentTransformRules::KeepRelativeTransform);
	LeverHandle->ComponentTags.Add("Lever");
	ReelLeft = CreateDefaultSubobject<UStaticMeshComponent>("ReelLeft");
	ReelLeft->AttachToComponent(Box, FAttachmentTransformRules::KeepRelativeTransform);
	ReelCenter = CreateDefaultSubobject<UStaticMeshComponent>("ReelCenter");
	ReelCenter->AttachToComponent(Box, FAttachmentTransformRules::KeepRelativeTransform);
	ReelRight = CreateDefaultSubobject<UStaticMeshComponent>("ReelRight");
	ReelRight->AttachToComponent(Box, FAttachmentTransformRules::KeepRelativeTransform);
	Light = CreateDefaultSubobject<UStaticMeshComponent>("Light");
	Light->AttachToComponent(Box, FAttachmentTransformRules::KeepRelativeTransform);
	Frame = CreateDefaultSubobject<USceneComponent>("Frame");
	Frame->AttachToComponent(Box, FAttachmentTransformRules::KeepRelativeTransform);
	FrameTop = CreateDefaultSubobject<UStaticMeshComponent>("FrameTop");
	FrameTop->AttachToComponent(Frame, FAttachmentTransformRules::KeepRelativeTransform);
	FrameBottom = CreateDefaultSubobject<UStaticMeshComponent>("FrameBottom");
	FrameBottom->AttachToComponent(Frame, FAttachmentTransformRules::KeepRelativeTransform);
	FrameOne = CreateDefaultSubobject<UStaticMeshComponent>("FrameOne");
	FrameOne->AttachToComponent(Frame, FAttachmentTransformRules::KeepRelativeTransform);
	FrameTwo = CreateDefaultSubobject<UStaticMeshComponent>("FrameTwo");
	FrameTwo->AttachToComponent(Frame, FAttachmentTransformRules::KeepRelativeTransform);
	FrameThree = CreateDefaultSubobject<UStaticMeshComponent>("FrameThree");
	FrameThree->AttachToComponent(Frame, FAttachmentTransformRules::KeepRelativeTransform);
	FrameFour = CreateDefaultSubobject<UStaticMeshComponent>("FrameFour");
	FrameFour->AttachToComponent(Frame, FAttachmentTransformRules::KeepRelativeTransform);
	
	spinTimeLeft = 0;
	ReelLeftSymbol = 1;
	ReelCenterSymbol = 1;
	ReelRightSymbol = 1;
}

// Called when the game starts or when spawned
void AMachine::BeginPlay()
{
	Super::BeginPlay();
	originalRotation = ReelLeft->GetRelativeRotation();
	
}

// Called every frame
void AMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (spinTimeLeft > 0)
	{
		GEngine->AddOnScreenDebugMessage(1, 5, FColor::Yellow, *FString::SanitizeFloat(spinTimeLeft));
		spinTimeLeft -= DeltaTime;
		if (spinTimeLeft <= 0)
		{
			LeverBase->AddLocalRotation(FRotator(0, 0, -90));
			ReelRight->SetRelativeRotation(originalRotation);
			ReelRight->AddLocalRotation(FRotator(0, (ReelRightSymbol*22.5), 0));
			
		}
		if (spinTimeLeft <= 2)
		{
			ReelLeft->SetRelativeRotation(originalRotation);
			ReelLeft->AddLocalRotation(FRotator(0, (ReelLeftSymbol*22.5), 0));
		}
		if (spinTimeLeft <= 1)
		{
			ReelCenter->SetRelativeRotation(originalRotation);
			ReelCenter->AddLocalRotation(FRotator(0, (ReelCenterSymbol*22.5), 0));
		}
		ReelRight->AddLocalRotation(FRotator(0, FMath::RandRange(-10,-5), 0));
		if (spinTimeLeft > 1)
		{
			ReelCenter->AddLocalRotation(FRotator(0, FMath::RandRange(-10,-5), 0));

			if (spinTimeLeft > 2)
			{
				ReelLeft->AddLocalRotation(FRotator(0, FMath::RandRange(-10,-5), 0));
			}
		}
	}

}

void AMachine::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved,
	FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
	if(MyComp->ComponentHasTag("Lever") && spinTimeLeft <= 0)
	{
		LeverBase->AddLocalRotation(FRotator(0,0,90));
		SpinReels(5.0);
	}
}

void AMachine::SpinReels(float time)
{
	spinTimeLeft = time;
	ReelLeftSymbol = FMath::RandRange(1, 16);
	ReelCenterSymbol = FMath::RandRange(1, 16);
	ReelRightSymbol = FMath::RandRange(1, 16);
}

