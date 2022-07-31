// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SAttributeComponent.h"
#include "GameFramework/Character.h"
#include "SAICharacter.generated.h"

class UPawnSensingComponent;
class USAttributeComponent;

UCLASS()
class ACTIONROGUELIKE_API ASAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASAICharacter();

protected:

	UPROPERTY(VisibleAnywhere,Category = "Effects")
	FName TimeToHitParamName;
	
	UFUNCTION()
	void OnHealthChanged(AActor* InstigatorActor, USAttributeComponent* OwningComp, float NewHealth, float Delta);
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void PostInitializeComponents() override;
	
	UPROPERTY(VisibleAnywhere,Category = "Components")
		UPawnSensingComponent* PawnSensingComp;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Components")
		USAttributeComponent* AtrributeComp;

	UFUNCTION()
	void SetTargetActor(AActor* NewTarget);
	
	UFUNCTION()
	void OnPawnSeen(APawn* Pawn);

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
