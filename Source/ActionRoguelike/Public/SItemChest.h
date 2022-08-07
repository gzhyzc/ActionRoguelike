// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SGameplayInterface.h"
#include "SItemChest.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ASItemChest : public AActor,public ISGameplayInterface
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	float TargetPitch;

	void Interact_Implementation(APawn* InstigatorPawn);

	void OnActorLoaded_Implementation();

protected:

	UPROPERTY(ReplicatedUsing = "OnRep_LidOpened", BlueprintReadOnly,SaveGame)
	bool bLidOpened;

	UFUNCTION()
	void OnRep_LidOpened();

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Mesh")
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Mesh")
	UStaticMeshComponent* LidMesh;


public:	

	// Sets default values for this actor's properties
	ASItemChest();

};
