//
// Created by Jacob on 2021-09-24.
//
#include <iostream>
#include "GameEngine.h"

//TODO allow for non lowercase in phrase and guesses
using namespace std;
GameEngine::GameEngine(int guesses, string phrase1):
        phrase(phrase1),
        guessesRemaining(guesses),
        unguessedPhrase(generateUnguessedPhrase()),
        numberOfCharacters(numberOfNonSpaceChar(phrase1)),
        numberRemaining(numberOfCharacters){
    opening();
    char currentGuess;
    while(true){
        if(guessesRemaining == 0){

            space();
            cout << "You ran out of guesses!\nthe phrase was:\n" << phrase<< endl << endl;
            break;
        }
        if(numberRemaining == 0){

            space();
            cout << "You WIN!\nthe phrase was:\n" << phrase<< endl << endl;
            break;
        }
        currentGuess = makeGuess();
        guess(currentGuess);
    };
}

void GameEngine::guess(char guess) {
    bool correct = false;

    for(int i = 0; i < phrase.length(); ++i){
        if(unguessedPhrase.at(i) == guess){
            space();
            cout << "You've already guessed this letter!\n" << "The phrase is still:\n" << unguessedPhrase << endl << "You have "
                 << guessesRemaining << " guesses remaining\n";
            return;
        }
    }

    for(int i = 0; i < phrase.length(); ++i){
        if(phrase.at(i) ==  guess){
            correct = true;
            unguessedPhrase.at(i) = phrase.at(i);
            numberRemaining--;
        }
    }
    space();
    if(numberRemaining == 0){
        return;
    }

    if(correct){
        cout << "You guessed correctly!\n" << "The phrase is now:\n" << unguessedPhrase << endl << "You have " << guessesRemaining << " guesses remaining\n";
    }else{
        guessesRemaining--;
        if(guessesRemaining == 1){
            cout << "You guessed wrong!\n" << "The phrase is still:\n" << unguessedPhrase << endl << "You have " << guessesRemaining << " guess remaining\n";
        }else {
            cout << "You guessed wrong!\n" << "The phrase is still:\n" << unguessedPhrase << endl << "You have "
                 << guessesRemaining << " guesses remaining\n";
        }
    }

    return;
}

string GameEngine::generateUnguessedPhrase() {
    string temp;
    for(int i = 0; i < phrase.length(); i++){
        char tempChar = phrase.at(i);
        switch (tempChar) {
            case ' ':
                temp.push_back(' ');
                break;
            default:
                temp.push_back('_');
                break;
        }
    }
    return temp;
}

void GameEngine::opening() {
    space();

    cout << "The outline of your phrase is as follows:\n";

    cout << unguessedPhrase << endl;

}

//TODO make sure guess is a char
char GameEngine::makeGuess() {
    cout << "Please enter a letter as a guess:\n";
    char guess;
    cin >> guess;
    return guess;
}

void GameEngine::space() {
    for(int i = 0; i < 30; i++) {
        cout << "\n";
    }
}

int GameEngine::numberOfNonSpaceChar(string phrase1) {
    int count = 0;
    for(int i = 0; i < phrase1.length(); i++){
        if(!isspace(phrase1.at(i))){
            count++;
        }
    }
    return count;
}