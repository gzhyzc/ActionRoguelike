

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/SizeBox.h"
#include "SWorldUserWidget.generated.h"

class USizeBox;

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API USWorldUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, Category = "UI")
		FVector WorldOffset;

	UPROPERTY(meta = (BindWidget))
		USizeBox*  ParentSizeBox;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);

public:

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (ExposeOnSpawn = true))
		AActor* AttachedActor;
	
};
