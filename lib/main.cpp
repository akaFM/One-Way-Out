#include "../include/Map.h"
#include "../include/Room.h"
#include "../include/Player.h"
#include <string>
#include <iostream>
#include <sstream>
#include <utility>
using namespace std;

class CommandParser {
public:
    CommandParser(Map*, Player*);
    void runGame();
    void assignCommandAndParameter(const string& uInput, string& command, string& param);
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
        cout << ">> Enter your command: ";
        getline(cin, userInput);
        if (userInput == "exit") {
            break; 
        }
        if (userInput.size() > 0 && userInput.size() < 25) {
            string command, parameter;
            assignCommandAndParameter(userInput, command, parameter);
            // MAKE THE COMMAND AND PARAMETER LOWERCASE BEFORE PASSING IT TO EXECUTECOMMAND
            executeCommand(command, parameter);
        } else {
            cout << "Invalid input. Please enter a valid command." << endl;
        }
    }
}

void CommandParser::assignCommandAndParameter(const string& uInput, string& command, string& param){

    size_t firstWhitespacePosition = uInput.find(" ");
    
    //case: the entire input has no spaces, meaning it's all one word
    if(firstWhitespacePosition == string::npos){ //sidenote: npos is a flag that says a given char wasn't found
        command = uInput;
        param = "";
        return;
    }

    //case: there is a space, meaning two words. seperate and assign the two words.
    command = uInput.substr(0, firstWhitespacePosition);
    param = uInput.substr(firstWhitespacePosition + 1);
    return;

}

void CommandParser::executeCommand(string command, string parameter) {
    if (command == "look") {
        map->printCurrentRoomInfo();
    } 
    else if (command == "use") {
        // TODO: 'USE' COMMAND
        cout << "\nThis still needs to be implemented!\n" << endl; 
    } 
    else if (command == "north" || command == "south" || command == "west" || command == "east") {
        map->moveDirection(command);
    } 
    else if (command == "go"){
        map->moveDirection(parameter);
    }
    else if (command == "drop"){
        player->deductItemFromInventory(parameter, map->getPlayerPosition());
    }
    else if (command == "take"){
        player->takeItemFromRoom(parameter, map->getPlayerPosition());
    }
    else if (command == "inventory" || command == "i"){
        player->printInventory();
    }
    else if (command == "examine"){
        player->examineItem(parameter);
    }
    else if (command == "help") {
        cout << "\nCOMMANDS\n--------------------" << endl;
        cout << "Inventory -> Check your current inventory." << endl;
        cout << "Look -> View information about your current position." << endl;
        cout << "Go [Direction] -> Travel in a certain direction, if possible." << endl; 
        cout << "Take [Item] -> Take an item from a room, if it exists." << endl;
        cout << "Drop [Item] -> Drop an item into a room, if you possess it." << endl;
        cout << "Examine [Item] -> View the name and description of an item, if you possess it." << endl;
        cout << "Use [Item] -> Use an item that exists in your inventory.\n" << endl;
    } 
    else {
        cout << "\nUnknown command. Type 'help' for the list of avaliable commands.\n" << endl;
    }
}

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

