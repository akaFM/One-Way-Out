#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string getFirstWord(const string& userInput) {
    size_t usePos = userInput.find("use");
    size_t lookPos = userInput.find("look");
    size_t goPos = userInput.find("go");
    if (usePos != string::npos) { //read as if "use" was found in userInput then return "use"
        return "use";
    } 
    else if (lookPos != string::npos) { //read as else if "look" was found in userInput then return "look"
        return "look";
    } 
    else if (goPos != string::npos) { //read as else if "go" was found in userInput then return "go"
        return "go";
    }
    else {
        return ""; //else return "" because use, look, and go wasn't found in userInput 
    }
}

string getRestOfWord (const string& userInput) {
    string parameter = getFirstWord(userInput);   //check which command was found within userInput

    if (!parameter.empty()) {                     
        size_t pos = userInput.find(parameter);   //set position after "use" "look" or "go" from userInput
        return userInput.substr(pos + parameter.length());  //returns whatever is after the following: use, look, or go
    } else {
        return userInput; //if none is found then just return userInput
    }
}
void executeCommand(string command, string parameter) {
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
        //help();
        cout << "Help?";
    } 
    else {
        cout << "Unknown command. Type 'help' for the list of avaliable commands." << endl;
    }
}
void runGame() {
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

void assignCommandAndParameter(const string& uInput, string& command, string& param){

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



int main() {
    string userInput;
    string command;
    string parameter;

    cout << "Enter a command: ";
    cin >> userInput;
    runGame();

    command = getFirstWord(userInput);
    parameter = getRestOfWord(userInput);

    executeCommand(getFirstWord(userInput), getRestOfWord(userInput));

    string userInput2 = "usegun";
    string command2 = "use";
    string parameter2 = "gun";
    assignCommandAndParameter(userInput2,command2,parameter2);
    cout << "assignCommandAndParameter -> " << "command: " << command2 << " parameter: " << parameter2 <<  endl;

    string userInput3 = " usegun";
    string command3 = "use";
    string parameter3 = "gun";
    assignCommandAndParameter(userInput3,command3,parameter3);
    cout << "assignCommandAndParameter -> " << "command: " << command3 << " parameter: " << parameter3 <<  endl;

    string userInput4 = "use gun";
    string command4 = "use";
    string parameter4 = "gun";
    assignCommandAndParameter(userInput4,command4,parameter4);
    cout << "assignCommandAndParameter -> " << "command: " << command4 << " parameter: " << parameter4 <<  endl;

    cout << "Command: " << command << endl;
    cout << "Parameter: " << parameter << endl;
    

    return 0;
}
