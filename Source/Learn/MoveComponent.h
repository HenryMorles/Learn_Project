// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoveComponent.generated.h"

class UCameraComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LEARN_API UMoveComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMoveComponent();

	UFUNCTION(BlueprintCallable)
	AActor* TraceLine(bool DebugLine);

	UFUNCTION(BlueprintCallable)
	AActor* LevetateObject();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	APawn* OwnerCharacter;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UCameraComponent* OwnerCamera;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector GrabLocation;

	float LineDistance;
	float DistanceToTransferredObject;

	AActor* MoveActor;
};
