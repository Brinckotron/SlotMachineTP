// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
	UStaticMeshComponent* Lever;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ReelLeft;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ReelCenter;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ReelRight;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Light;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

};
