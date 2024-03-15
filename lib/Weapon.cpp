#include <iostream>
#include "../include/Weapon.h"

using namespace std; 

//creates object that has base dmg and name/class of what the weapon is

//constructors
    Weapon::Weapon() : damage(0)
    {
        Weapon w; 
        w.setName("");
        w.setDescription("");
    }

    Weapon::Weapon(string name, string description, int dmg) : damage(dmg)
    {
        Weapon w; 
        w.setName(name);
        w.setDescription(description);
    }

//setters 
    void Weapon::setDamage(int dmg) { damage = dmg; }

//getters
    int Weapon::getDamage() { return damage; }