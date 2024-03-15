#include <iostream>
#include "../include/Key.h"

using namespace std; 

//key condition will either be Great, good, alright, bad, broken -> depending on condition it can work or not

//constructors
    Key::Key() : condition("Great condition. Key Works!")
    {
        Key k; 
        k.setName("");
        k.setDescription("");
    }

    Key::Key(string name, string description, string condition) : condition("Great condition. Key Works!")
    {
        Key k;
        k.setName(name);
        k.setDescription(description);
    }

//setter
    void Key::setCondition(string c) { condition = c; }

//getter
    string Key::getCondition() { return condition; }