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

int main() {
    string userInput;
    string command;
    string parameter;

    cout << "Enter a command: ";
    cin >> userInput;

    command = getFirstWord(userInput);
    parameter = getRestOfWord(userInput);

    cout << "Command: " << command << endl;
    cout << "Parameter: " << parameter << endl;

    return 0;
}
