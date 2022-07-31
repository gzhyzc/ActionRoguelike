// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SBTTask_RangeAttack.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API USBTTask_RangeAttack : public UBTTaskNode
{
	GENERATED_BODY()
	
protected:
	
	UPROPERTY(EditAnywhere, Category = "AI")
	float MaxBulletSpread;
	
	UPROPERTY(EditAnywhere,Category = "AI")
	TSubclassOf<AActor> ProjectileClass;
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

public:
	USBTTask_RangeAttack();
};
