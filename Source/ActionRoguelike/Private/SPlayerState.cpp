// Fill out your copyright notice in the Description page of Project Settings.


#include "SPlayerState.h"

int32 ASPlayerState::GetCredits() const
{
	return Credits;
}

void ASPlayerState::AddCredits(int32 Delta)
{
	// Avoid user-error of adding a negative amount
	if (!ensure(Delta >= 0.0f))
	{
		return;
	}

	Credits += Delta;

	OnCreditsChanged.Broadcast(this, Credits, Delta);
}

bool ASPlayerState::RemoveCredits(int32 Delta)
{
	// Avoid user-error of adding a subtracting negative amount
	if (!ensure(Delta >= 0.0f))
	{
		return false;
	}

	if (Credits < Delta)
	{
		// Not enough credits available
		return false;
	}

	Credits -= Delta;

	OnCreditsChanged.Broadcast(this, Credits, -Delta);

	return true;
}

void ASPlayerState::LoadPlayerState_Implementation(USSaveGame* SaveObject)
{
	if (SaveObject)
	{
		Credits = SaveObject->Credits ;
		// FPlayerSaveData* FoundData = SaveObject->GetPlayerData(this);
		// if (FoundData)
		// {
		// 	//Credits = SaveObject->Credits;
		// 	// Makes sure we trigger credits changed event
		// 	AddCredits(FoundData->Credits);
		//
		// 	PersonalRecordTime = FoundData->PersonalRecordTime;
		// }
		// else
		// {
		// 	UE_LOG(LogTemp, Warning, TEXT("Could not find SaveGame data for player id '%i'."), GetPlayerId());
		// }
	}
}

void ASPlayerState::SavePlayerState_Implementation(USSaveGame* SaveObject)
{
	if (SaveObject)
	{
		SaveObject->Credits = Credits;
		// // Gather all relevant data for player
		// FPlayerSaveData SaveData;
		// SaveData.Credits = Credits;
		// SaveData.PersonalRecordTime = PersonalRecordTime;
		// // Stored as FString for simplicity (original Steam ID is uint64)
		// SaveData.PlayerID = GetUniqueId().ToString();
		//
		// // May not be alive while we save
		// if (APawn* MyPawn = GetPawn())
		// {
		// 	SaveData.Location = MyPawn->GetActorLocation();
		// 	SaveData.Rotation = MyPawn->GetActorRotation();
		// 	SaveData.bResumeAtTransform = true;
		// }
		//
		// SaveObject->SavedPlayers.Add(SaveData);
	}
}
