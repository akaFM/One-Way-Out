#include <iostream>
#include "../include/Weapon.h"

using namespace std; 

//creates object that has base dmg and name/class of what the weapon is

//constructors
    Weapon::Weapon() : damage(0), weaponType("")
    {}

    Weapon::Weapon(int dmg, string wT) : damage(dmg), weaponType(wT)  
    {}

//setters 
    void Weapon::setDamage(int dmg) { damage = dmg; }

    void Weapon::setWeaponType(string wT) { weaponType = wT; }

//getters
    int Weapon::getDamage() { return damage; }

    string Weapon::getWeaponType() { return weaponType; }