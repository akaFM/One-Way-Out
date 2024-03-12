
#include <iostream>
#include <cstdlib>
#include "../include/Items.h"

using namespace std; 

//base class and will be used by Weapon, Consumables, and Key

//constructors
    Items::Items() : name(""), description("")
    {
        type = rand() % 3;
    }

    Items::Items(string n, string d, int t) : name(n), description(d), type(t)
    {}

//setter functions
    void Items::setName(string n){ name = n; }

    void Items::setDescription(string d){ description = d; }

    void Items::setType(int t) { type = t; }

//getter functions
    string Items::getName(){ return name; }

    string Items::getDescription(){ return description; }

    int Items::getType(){ return type; } 

    bool Items::itemExists(){ return name!= ""; }

    void Items::deleteItem(){
        name = "";
        description = "";
        type = 0;
    }
