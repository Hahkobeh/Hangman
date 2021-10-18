//
// Created by Jacob on 2021-09-24.
//

#ifndef HANGMAN_GAMEENGINE_H
#define HANGMAN_GAMEENGINE_H


#include <string>
using namespace std;

class GameEngine {
private:
    int guessesRemaining;
    int numberOfCharacters, numberRemaining;
    const string phrase;
    string unguessedPhrase;

public:
    GameEngine(int guesses, string phrase1);

    void guess(char);

    string generateUnguessedPhrase();


    int numberOfNonSpaceChar(string phrase1);

    void space();

    void opening();


    char makeGuess();

};


#endif //HANGMAN_GAMEENGINE_H
