#include <iostream>
#include "../include/Key.h"

using namespace std; 

//key condition will either be Great, good, alright, bad, broken -> depending on condition it can work or not

//constructors
    Key::Key() : condition("Great condition")
    {
        setName("Room Key");
        setDescription("Can be used to open a door");
    }

    Key::Key(string condition, string name, string description) : condition(condition)
    {
        setName(name);
        setDescription(description);
    }

//setter
    void Key::setCondition(string c) { condition = c; }

//getter
    string Key::getCondition() { return condition; }