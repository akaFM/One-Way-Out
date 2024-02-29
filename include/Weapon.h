#ifndef WEAPONS_H
#define WEAPONS_H

#include "../include/Items.h"

class Weapon : public Items {
    
    private:
        int damage;
        string weaponType; 

    public:
    //Constructors

        Weapon();
        Weapon(int dmg, string wT);

    //setters

        void setDamage(int dmg);
        void setWeaponType(string wT); 

    //getters

        int getDamage();
        string getWeaponType(); 


};

#endif

