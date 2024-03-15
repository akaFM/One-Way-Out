#include <iostream>
#include "../include/Consumables.h"

using namespace std; 

//changeHP is a int that is either pos/neg and will update player hp 
//consumableType is a string detaling what type it is poison, apple, health potion, etc. 

//constructors
    Consumables::Consumables() : changeHP(0)
    {
        setName("");
        setDescription("");
    }

    Consumables::Consumables(int cHP, string name, string description) : changeHP(cHP)
    {
        setName(name);
        setDescription(description);
    }

//setters
    void Consumables::setChangeHP(int hp) { changeHP = hp; }

//getters 
    int Consumables::getChangeHP(){ return changeHP; }


