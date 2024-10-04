// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactible.h"
#include "GameFramework/Actor.h"
#include "Machine.generated.h"

UCLASS()
class AMachine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMachine();
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Box;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* LeverBase;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LeverHandle;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ReelLeft;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ReelCenter;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ReelRight;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Light;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Frame;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* FrameTop;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* FrameBottom;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* FrameOne;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* FrameTwo;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* FrameThree;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* FrameFour;

	float spinTimeLeft;
	int ReelLeftSymbol;
	int ReelCenterSymbol;
	int ReelRightSymbol;
	FRotator originalRotation;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	virtual void SpinReels(float time);
};
