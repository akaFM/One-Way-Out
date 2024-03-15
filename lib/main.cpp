#include "../include/Map.h"
#include "../include/Room.h"
#include "../include/CommandParser.h"
#include <string>
#include <iostream>
using namespace std;

int main() {

    // TODO: Intro Screen
    // Give title of game, authors, and prompt user for difficulty.
    cout << "Welcome to One Way Out!" << std::endl;
    cout << "Authors: Avo Karamusyan, Vincent Tang, Andrew Pham, Benjamin Nguyen and Thien Pham" << std::endl;
    cout << "Select difficulty (1 for easy, 2 for hard): ";
    // int difficulty = user input for difficulty (1 for easy, 2 for hard)
    //int difficulty;
    //cin >> difficulty;
    // Map m; --> This initializes the full map and all of its rooms.
    Map m;
    //Comment: m.initializeMap(string)
    // Player p(int difficulty); --> In the player class, attributes "health" and "stepsRemaining" will be determined by the passed-in difficulty (see UML diagram).
    Player p(difficulty);
    // CommandParser c(m, p); --> This initializes the commandParser, which will be called to begin the user input loop and seperate input strings as commands.
    CommandParser c(&m, &p);



    // The "map" and "player" passed into the CommandParser constructor are stored as attributes in CommandParser since they need to be accessed continuously.

    // c.runGame();
    c.runGame();

    return 0;

}

