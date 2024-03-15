#include "../include/Map.h"
#include "../include/Room.h"
#include "../include/CommandParser.h"
#include "../include/Player.h"
#include <string>
#include <iostream>
#include <sstream>
#include <utility>
using namespace std;

int main() {
    
    // TODO: Intro Screen
    // Give title of game, authors, and prompt user for difficulty.
    cout << "\nWelcome to One Way Out!" << endl;
    cout << "Authors: Avo Karamusyan, Vincent Tang, Andrew Pham, Benjamin Nguyen and Thien Pham" << endl;

    bool valid = false;
    int difficulty;

    //loop to collect difficulty w/ input validation
    while(!valid){

        cout << "\nSelect difficulty (1 for easy, 2 for hard): ";
        if(cin >> difficulty){

            if(difficulty != 1 and difficulty != 2){ //case: invalid integer provided.
                cout << "\nPlease choose from the numbers provided." << endl;
            }
            else{ //case: valid integer provided.
                valid = true;
                break;
            }

        } else {
            cout << "\nInvalid choice. Please follow directions." << endl;
            cin.clear();
        }

        cin.ignore(100, '\n'); //ignore everything else up to the newline

    }

    cin.ignore(); // moves the buffer past newline for when commandParser runGame() is invoked

    // This initializes the full map and all of its rooms.
    Map m;

    // Player p(int difficulty); --> In the player class, attributes "health" and "stepsRemaining" will be determined by the passed-in difficulty (see UML diagram).
    Player p(difficulty);

    // CommandParser c(m, p); --> This initializes the commandParser, which will be called to begin the user input loop and seperate input strings as commands.
    // The "map" and "player" passed into the CommandParser constructor are stored as attributes in CommandParser since they need to be accessed continuously.
    CommandParser c(&m, &p);
    
    c.runGame();

    return 0;

}

