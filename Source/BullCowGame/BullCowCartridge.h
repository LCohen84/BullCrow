// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;
	void SetupGame();
	int32 Lives;
	bool bGameOver;
	void EndGame();
	void ProcessGuess(const FString& Guess);
	bool IsIsogram(const FString& Word);
	TArray<FString> GetValidWords(const TArray<FString>&) const;

	// Your declarations go below!
	private:
	FString HiddenWord;
	
};
