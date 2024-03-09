#include "../include/Map.h"
#include "../include/Room.h"
#include <string>
#include <iostream>
using namespace std;

class Player {
public:
    Player(int difficulty);
};

Player::Player(int difficulty) {
    if (difficulty == 1) {
        cout << "easy mode" << endl;
    }
    else if (difficulty == 2) {
        cout << "hard mode" << endl;
    }
    else {
        cout << "invalid mode" << endl;
    }
}

class CommandParser {
public:
    CommandParser(Map*, Player*);
    void runGame();
    string getFirstWord(string input);
    string getRestOfWord(string input);
    void executeCommand(string m , string p);
    void help();

private:
    Map* map;
    Player* player;
};

CommandParser::CommandParser(Map* map, Player* player) : map(map), player(player) {}

void CommandParser::runGame() {
    string userInput;
    while (true) {
        cout << "Enter your command: ";
        getline(cin, userInput);
        if (userInput == "exit") {
            break; 
        }
        if (userInput.size() > 0 && userInput.size() < 25) {
            string command = getFirstWord(userInput);
            string parameter = getRestOfWord(userInput);
            executeCommand(command, parameter);
        } else {
            cout << "Invalid input. Please enter a valid command." << endl;
        }
    }
}

string CommandParser::getFirstWord(const string& userInput) {
    size_t usePos = userInput.find("use");
    size_t lookPos = userInput.find("look");
    size_t goPos = userInput.find("go");
    if (usePos != string::npos) { 
        return "use";
    } 
    else if (lookPos != string::npos) { 
        return "look";
    } 
    else if (goPos != string::npos) { 
        return "go";
    }
    else {
        return "";
}

string CommandParser::getRestOfWord(const string& userInput) {
    string parameter = getFirstCommand(userInput);
    if (!parameter.empty()) {
        size_t pos = userInput.find(parameter);
        return userInput.substr(pos + parameter.length());
    } else {
        return userInput;
    }
}

void CommandParser::executeCommand(string command, string parameter) {
    if (command == "look") {
        cout << "Looking around the room..." << endl;
    } 
    else if (command == "use") {
        // call use command in Item class
        cout << "Using item: " << parameter << " (Item class)" << endl;
    } 
    else if (command == "go") {
        // call moveDirection command in Map class
        cout << "Heading to another location..." << endl;
    } 
    else if (command == "help") {
        help();
    } 
    else {
        cout << "Unknown command. Type 'help' for the list of avaliable commands." << endl;
    }
}

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

