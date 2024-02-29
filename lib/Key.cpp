#include <iostream>
#include "../include/Key.h"

using namespace std; 

//constructors
    Key::Key() : condition("Great condition. Key Works!")
    {}

//setter
    void Key::setCondition(string c) { condition = c; }

//getter
    string Key::getCondition() { return condition; }