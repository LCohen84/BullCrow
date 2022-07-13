// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"
#include <iostream>

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame(); // setting up the game

    PrintLine(TEXT("There are %i possible words!"), HiddenWordList.Num());
    PrintLine(TEXT("The HiddenWord is: %s"), *HiddenWord);
    
    GetValidWords();
}

void UBullCowCartridge::OnInput(const FString& PlayerInput) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }

    else
    {
        ProcessGuess(PlayerInput);        
    }    
}

void UBullCowCartridge::SetupGame()
{
    // Welcoming the player
    PrintLine(TEXT(" Hi There! Welcome to Bulls Crows Game. "));
    HiddenWord = TEXT("fight");
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Please guess %i letter word."), HiddenWord.Len());
    PrintLine(TEXT("You will have %i lives."), Lives);
    PrintLine(TEXT("Type in your guess. \nPress enter to continue. "));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again."));
}


void UBullCowCartridge::ProcessGuess(const FString& Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT(" You guess the correct word! Congrats, you won! "));
        EndGame();
        return;
    }
  
    // check user input
    if (Guess.Len() == 0)// check if the number of charcters are correct
    {
        PrintLine(TEXT("You didn't type in a word \n Try again!"));
        return;
    }
    
    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT(" The Hiddenword is %i characters long. \n Try again!"), HiddenWord.Len());
        PrintLine(TEXT(" You have %i lives left"), Lives);
        return;
    } 
    
    if (!IsIsogram(Guess))
    {
        PrintLine(TEXT("There are no repeating letters, try again!"));
        return;
    }
    //if (!IsIsogram)// check if it isogram
    //{
    //    PrintLine(TEXT("There are no repeating letters, try again!"));
    //}
    // subtract life

    // check if lives are greater than 0
    // if it true, go again
    // show lives
    // if false, show game over
    // ask do you want play again
    
    PrintLine(TEXT("You lost a Life"));
    --Lives;

    if (Lives == 0)
    {
        ClearScreen();
        PrintLine(TEXT(" You have lost. Nice try!"));
        EndGame();
        return;
    }

    
    PrintLine(TEXT("You have %i live left, try again!"), Lives);
}

bool UBullCowCartridge::IsIsogram(const FString& Word)
{
    for (int32 Index = 0; Index < Word.Len(); Index++)
    {
        for (int32 Comparison = Index + 1; Comparison < Word.Len(); Comparison++)
        {
            if (Word[Comparison] == Word[Index])
            {
                return false;
            }
        }   
    }
    /*for (int Index = 0, Comparison = Index +1; Index < Word.Len(); Index++)
    {
        PrintLine(TEXT("%c"), Word[Index]);
        if (Word[Index] == Word[Comparison])
        {
            return false;
        }
    }*/
    return true;
}

//TArray<FString> UBullCowCartridge::GetValidWords(TArray<FString>) const
//{
//    return TArray<FString>();
//}


TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordList) const
{
    TArray<FString> ValidWords;

    for (FString Words : WordList)
    {
        if (Words.Len() >= 4 && Words.Len() <= 8)
        {
            if (IsIsogram)
            {
                ValidWords.Emplace(Words);
            }
        }
        //PrintLine(TEXT("%s"), *WordList[Index]);
    }

    return ValidWords;
}