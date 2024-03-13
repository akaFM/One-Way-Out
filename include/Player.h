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
        const int hasItem(string itemName); //helper: returns index of item in inv, -1 otherwise
    
    public:

        Player(int difficulty);

        //Health Attributes
        int getHealth();
        void setHealth(int hp);
        void deductHealth(int hp);

        //Steps Attributes
        int getSteps();
        void deductSteps(int step);

        //Inventory Attributes
        void deductItemFromInventory(const string itemName, Room* currRoom); // removes item from personal inv, drops into room inv
        void takeItemFromRoom(const string itemName, Room * currRoom); // removes item from room inv, adds to personal inv
        void printInventory();

};

#endif