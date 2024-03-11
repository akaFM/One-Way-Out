#ifndef CONSUMABLES_H
#define CONSUMABLES_H

#include "../include/Items.h"

class Consumables : public Items{

    private: 
        int changeHP;
        string consumableType; 

    public:

    //Constructors
        Consumables();

        Consumables(int cHP, string cT);

    //setters
        void setChangeHP(int hp);
        void setConsumableType(string cT); 

    //getters
        int getChangeHP();
        string getConsumableType(); 

};

#endif