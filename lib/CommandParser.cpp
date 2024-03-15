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

    printIntroductoryDialogue();
    
    string userInput;
    while(!player->checkIfGameOver()) {

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
    if (command == "look" || command == "l") {
        map->printCurrentRoomInfo();
    } 
    else if (command == "use" || command == "u") {
        player->findAndUseItem(parameter, map->getPlayerPosition());
    } 
    else if (command == "north" || command == "south" || command == "west" || command == "east") {
        map->moveDirection(command);
        player->deductSteps(1);
    } 
    else if (command == "go" || command == "g"){
        map->moveDirection(parameter);
        player->deductSteps(1);
    }
    else if (command == "drop" || command == "d"){
        player->deductItemFromInventory(parameter, map->getPlayerPosition());
    }
    else if (command == "take" || command == "t"){
        player->takeItemFromRoom(parameter, map->getPlayerPosition());
    }
    else if (command == "inventory" || command == "i"){
        player->printInventory();
    }
    else if (command == "examine" || command == "e"){
        player->examineItem(parameter);
    }
    else if (command == "steps" || command == "s"){
        player->printSteps();
    }
    else if (command == "help" || command == "h") {
        help();
    } 
    else {
        cout << "\nUnknown command. Type 'help' for the list of avaliable commands.\n" << endl;
    }
}

void CommandParser::help() {
    cout << "\nCOMMANDS\n--------------------" << endl;
    cout << "Inventory -> Check your current inventory." << endl;
    cout << "Look -> View information about your current position." << endl;
    cout << "Steps -> View how many steps left you have to beat the game." << endl;
    cout << "Go [Direction] -> Travel in a certain direction, if possible." << endl; 
    cout << "Take [Item] -> Take an item from a room, if it exists." << endl;
    cout << "Drop [Item] -> Drop an item into a room, if you possess it." << endl;
    cout << "Examine [Item] -> View the name and description of an item, if you possess it." << endl;
    cout << "Use [Item] -> Use an item that exists in your inventory.\n" << endl;
}

void CommandParser::printIntroductoryDialogue(){
    cout << "\nYou wake up in a trashed hotel room with zero recollection of how you got there. As you realize that all of your belongings are gone, it dawns upon you that you have been abducted! There is no immediate sign of the perpetrator, but you start to feel anxious and dizzy. There's only so much time- find your way out!" << endl;
    cout << "\n[!] Enter 'help' for a list of commands.\n" << endl;
}
