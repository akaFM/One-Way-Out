#ifndef CONSUMABLES_H
#define CONSUMABLES_H

#include "../include/Items.h"

class Consumables : public Items{

    private: 
        int changeHP;

    public:

    //Constructors
        Consumables();

        Consumables(string name, string description, int cHP);

    //setters
        void setChangeHP(int hp);

    //getters
        int getChangeHP();

};

#endif