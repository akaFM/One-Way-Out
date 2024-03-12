#ifndef PLAYER_H
#define PLAYER_H
#include "../include/Items.h"
#include "../include/Room.h"
#include <vector>
using namespace std;

class Player {
    private: 
        vector<Items> inventory;
        int health;
        int stepsRemaining;
    public:
        Player(int Difficulty);
        //Health Attributes
        int getHealth();
        void setHealth(int hp);
        void deductHealth(int hp);

        //Steps Attributes
        int getSteps();
        void deductSteps(int step);

        //Inventory Attributes
        bool hasItem(Items item);
        void deductItem(Items item, Room* room);
        void giveItem(Items item);
};

#endif