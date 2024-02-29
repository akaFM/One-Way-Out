#include <iostream>
#include "../include/Items.h"

using namespace std; 

//base class and will be used by Weapon, Consumables, and Key

//constructors
    Items::Items() : name(""), description(""), type("")
    {}

    Items::Items(string n, string d, string t) : name(n), description(d), type(t)
    {}

//setter functions
    void Items::setName(string n){ name = n; }

    void Items::setDescription(string d){ description = d; }

    void Items::setType(string t) { type = t; }

//getter functions
    string Items::getName(){ return name; }

    string Items::getDescription(){ return description; }

    string Items::getType(){ return type; } 