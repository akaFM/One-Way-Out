#include <iostream>
#include "../include/Key.h"

using namespace std; 

//key condition will either be Great, good, alright, bad, broken -> depending on condition it can work or not

//constructors
    Key::Key() : nameOfRoomOpened("Room 1")
    {
        setName("Room Key");
        setDescription("Can be used to open a door");
    }

    Key::Key(string nameOfRoomOpened, string name, string description) : nameOfRoomOpened(nameOfRoomOpened)
    {
        setName(name);
        setDescription(description);
    }

//setter
    void Key::setNameOfRoomOpened(string n) { nameOfRoomOpened = n; }

//getter
    string Key::getNameOfRoomOpened() { return nameOfRoomOpened; }