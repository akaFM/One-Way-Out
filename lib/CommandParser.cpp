#include "CommandParser.h"
#include <iostream>

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