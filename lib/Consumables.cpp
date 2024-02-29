#include <iostream>
#include "../include/Consumables.h"

using namespace std; 

//changeHP is a int that is either pos/neg and will update player hp 
//consumableType is a string detaling what type it is poison, apple, health potion, etc. 

//constructors
    Consumables::Consumables() : changeHP(0), consumableType("")
    {}

    Consumables::Consumables(int cHP, string cT) : changeHP(cHP), consumableType(cT)
    {}

//setters
    void Consumables::setChangeHP(int hp) { changeHP = hp; }

    void Consumables::setConsumableType(string cT) { consumableType = cT; }

//getters 
    int Consumables::getChangeHP(){ return changeHP; }

    string Consumables::getConsumableType() { return consumableType; }

