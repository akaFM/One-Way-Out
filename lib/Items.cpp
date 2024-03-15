
#include <iostream>
#include <cstdlib>
#include "../include/Items.h"

using namespace std; 

//base class and will be used by Weapon, Consumables, and Key

//constructors
    Items::Items() : name(""), description("")
    {}
 
    Items::Items(string n, string d) : name(n), description(d)
    {}

//setter functions
    void Items::setName(string n){ name = n; }

    void Items::setDescription(string d){ description = d; }


//getter functions
    string Items::getName(){ return name; }

    string Items::getDescription(){ return description; }

    bool Items::itemExists(){ return name!= ""; }

    void Items::deleteItem(){
        name = "";
        description = "";
    }
