#include <iostream>
#include "../include/Weapon.h"

using namespace std; 

//creates object that has base dmg and name/class of what the weapon is

//constructors
    Weapon::Weapon() : damage(0)
    {
        setName("");
        setDescription("");
    }

    Weapon::Weapon(int dmg, string name, string description) : damage(dmg)
    { 
        setName(name);
        setDescription(description);
    }

//setters 
    void Weapon::setDamage(int dmg) { damage = dmg; }

//getters
    int Weapon::getDamage() { return damage; }