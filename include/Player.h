#ifndef PLAYER_H
#define PLAYER_H
#include "../include/Items.h"
#include "../include/Consumables.h"
#include "../include/Room.h"
#include <vector>
using namespace std;

class Player {
    private: 

        vector<Items> inventory;
        int health;
        int stepsRemaining;
        bool isGameOver = false;

        const int hasItem(string itemName); //helper: returns index of item in inv, -1 otherwise
        void useItem(Items itemToUse, Room * currentPlayerPosition);

    
    public:

        Player(int difficulty);

        //game status checkers
        bool checkIfGameOver(){
            return isGameOver;
        }

        void endGame(){
            isGameOver = true; 
        }

        //Health Attributes
        int getHealth();
        void setHealth(int hp);
        void deductHealth(int hp);

        //Steps Attributes
        int getSteps();
        void deductSteps(int step);
        void addSteps(const int numberOfStepsToAdd);

        //Inventory Attributes
        const bool isInventoryEmpty();
        void deductItemFromInventory(const string itemName, Room* currRoom); // removes item from personal inv, drops into room inv
        void takeItemFromRoom(const string itemName, Room * currRoom); // removes item from room inv, adds to personal inv
        void printInventory();
        void eatConsumable(Consumables consumable);

        void examineItem(const string itemName);
        void addItem(Items itemToAdd);
        void removeItem(const string itemName);
        void findAndUseItem(const string itemName, Room * currentPlayerPosition);

};

#endif