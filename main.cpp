#include <iostream>
#include "GameEngine.h"
#include <string>
#include <regex>


bool correctPhrase(string);
bool correctNumber(char*);

using namespace std;
int main() {
    bool cont = true;
    char contA;
    do{
        string phrase = "";
        do {
            cout << "Enter Phrase (letters and space only):\n";
            char buffer1[256];
            cin.getline(buffer1, 256);
            phrase = buffer1;

            // 65 - 90 + 97 - 122 inclusive also 32
        }while(phrase.length() == 0 || phrase.length() > 256 || !correctPhrase(phrase));


        int guesses = 0;
        string number;
        char* buffPointer;


        cout << "Enter number of guesses (digits only):\n";
        cin >> guesses;


        //TODO check if guesses is valid only number and less then 26
        /*do {
            cout << "Enter number of guesses (digits only):\n";
            char buffer2[8];
            buffPointer = &buffer2[0];
            cin.getline(buffer2, 8);
            number = buffer2;





        } while (!correctNumber(buffPointer));
        guesses = buffPointer[0];*/

        GameEngine game(guesses,phrase);




        cout << "Press enter to play again." << endl;
        cin.get();
        cin.get(contA);
        if(contA != '\n'){
            cont = false;
        }
    }while(cont);

    return 0;
}
//TODO can type whole word + dont lose a guess if you guess the same thing twice (but guess wrong)

bool correctPhrase(string phrase){
    bool correct = true;
    char character;
    for(int i  = 0; i < phrase.length(); ++i ){
        character = phrase.at(i);
        if( (character >= 65 && character <= 90) || (character >= 97 && character <= 122) || (character == 32)){

        }
        else{
            correct = false;
            break;
        }
    }


    return correct;
}

bool correctNumber(string number){
    bool correct = true;
    char character;
    for(int i  = 0; i < number.length(); ++i ){
        character = number.at(i);
        if( character >= 48 && character <= 57){

        }
        else{
            correct = false;
            break;
        }
    }


    return correct;
}
