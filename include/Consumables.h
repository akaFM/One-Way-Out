#ifndef CONSUMABLES_H
#define CONSUMABLES_H

#include "../include/Items.h"
#include <string>

class Consumables : public Items{

    private: 
        int changeHP;

    public:

    //Constructors
        Consumables();

        Consumables(int cHP, string name, string description);

    //setters
        void setChangeHP(int hp);

    //getters
        int getChangeHP();

};

#endif