#include <iostream>

#include "utilities.hpp"

int
checkCharactersAndPosition(char guess[], char code[], int length)
{
    int correct = 0;
    for (int i = 0; i < length; i++)
    {
        if (guess[i] == code[i]) correct++;
    }
    return correct;
}

int
checkCharacters(char guess[], char code[], int length, char start_letter, char end_letter)
{
    int correctCharacters = 0;
    for (char i = start_letter; i < end_letter; i++)
    {
        correctCharacters += (countOccurencesOfCharacter(guess, length, i) <
                             countOccurencesOfCharacter(code, length, i) ?
                             countOccurencesOfCharacter(guess, length, i) :
                             countOccurencesOfCharacter(code, length, i));
    }
    return correctCharacters;
}


void
playMastermind()
{
    int tries = 10;
    const int SIZE = 5, LETTERS = 6;
    char code[SIZE], guess[SIZE];
    bool win = false, play = true;
    char choice = 'y';
    while(play)
    {
        randomizeCString(code, SIZE, 'A', 'A'+(LETTERS-1));
        std::cout << "Let us play a game of mastermind." << std::endl
        << "Guess " << SIZE << " letters between " << 'A' << " and " <<static_cast<char>('A'+(LETTERS-1)) << std::endl;

        while(tries && !win)
        {
            std::cout << "You have " << tries << " left." << std::endl;   
            readInputToCString(guess, SIZE,'A', 'A'+(LETTERS-1));
            std::cout << "Your guess: " << guess << std::endl;

            int correctGuesses = checkCharactersAndPosition(guess, code, SIZE);

            std::cout << "You guessed " << correctGuesses << " letters in the correct position." << std::endl;

            int correctCharacters = checkCharacters(guess, code, SIZE, 'A', 'A' +(LETTERS-1));
            std::cout << "You guessed " << correctCharacters << " characters correctly!" << std::endl;

            if (correctGuesses == SIZE)
            {
                std::cout << "Congratulations, you win! You are clearly a mastermind" << std::endl;
                win = true;
            }
            else tries--;
        }
        if (!win){
            std::cout << "Sorry about the loss, mate, try again!" << std::endl;
        }
        std::cout << "Do you wanna play again?(y/n)" << std::endl;
        std::cin >> choice;
        if (choice == 'n')
        {
            play = false;
        }
    }
}
