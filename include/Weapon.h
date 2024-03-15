#ifndef WEAPONS_H
#define WEAPONS_H

#include "../include/Items.h"

class Weapon : public Items {
    
    private:
        int damage;

    public:
    //Constructors

        Weapon();
        Weapon(int dmg, string name, string description);

    //setters

        void setDamage(int dmg);

    //getters

        int getDamage();


};

#endif

