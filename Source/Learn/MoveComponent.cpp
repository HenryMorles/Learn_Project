// Fill out your copyright notice in the Description page of Project Settings.

#include "MoveComponent.h"
#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"

UMoveComponent::UMoveComponent() {

	PrimaryComponentTick.bCanEverTick = true;
	
	LineDistance = 1000;
	DistanceToTransferredObject = 150;
}

AActor* UMoveComponent::TraceLine(bool DebugLine) {

	if (OwnerCharacter && OwnerCamera) {

		FVector Location = OwnerCamera->GetComponentLocation();
		FRotator Rotation = OwnerCamera->GetComponentRotation();
		FHitResult Hit;

		FVector Start = Location + Rotation.Vector();
		FVector End = Location + (Rotation.Vector() * LineDistance);

		FCollisionQueryParams TraceParams;
		TraceParams.AddIgnoredActor(OwnerCharacter);

		bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Pawn, TraceParams);

		if (DebugLine) {

			DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 2.0f);

		}

		if (bHit) {

			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Hit")));
			
			MoveActor = Hit.GetActor();

			return Hit.GetActor();
		}
	}
	return 0;
}

void UMoveComponent::BeginPlay() {

	Super::BeginPlay();

}


AActor* UMoveComponent::LevetateObject() {

	if (MoveActor) {

		FVector LevitateLocation = MoveActor->GetActorLocation();
		LevitateLocation.Z += 10;
		MoveActor->SetActorLocation(LevitateLocation);

		MoveActor->SetActorLocation(GrabLocation);

		return MoveActor;
	}
	return 0;
}

void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

