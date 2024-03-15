#include "../include/CommandParser.h"
#include <iostream>
using namespace std;

CommandParser::CommandParser(Map* map, Player* player) : map(map), player(player) {}

string CommandParser::toLower(const string& str) {
    string lowerStr = str;
    for (char& c : lowerStr) {
        c = std::tolower(static_cast<unsigned char>(c));
    }
    return lowerStr;
}

void CommandParser::runGame() {
    cout << "\nEnter 'help' for a list of commands.\n" << endl;
    string userInput;
    while (true) {
        cout << ">> Enter your command: ";
        getline(cin, userInput);
        userInput = toLower(userInput);
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
