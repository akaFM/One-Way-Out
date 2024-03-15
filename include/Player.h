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
        bool isGameOver = false;

        const int hasItem(string itemName); //helper: returns index of item in inv, -1 otherwise
        void useItem(Items itemToUse, Room * currentPlayerPosition);

    
    public:

        Player(int difficulty);

        bool checkIfGameOver(){
            return isGameOver;
        }
        void endGame(){
            cout << "YOU WIN!\nThank you for playing!\n" << endl;
            isGameOver = true; 
        }

        //Health Attributes
        int getHealth();
        void setHealth(int hp);
        void deductHealth(int hp);

        //Steps Attributes
        int getSteps();
        void deductSteps(int step);

        //Inventory Attributes
        const bool isInventoryEmpty();
        void deductItemFromInventory(const string itemName, Room* currRoom); // removes item from personal inv, drops into room inv
        void takeItemFromRoom(const string itemName, Room * currRoom); // removes item from room inv, adds to personal inv
        void printInventory();

        void examineItem(const string itemName);
        void addItem(Items itemToAdd);
        void removeItem(const string itemName);
        void findAndUseItem(const string itemName, Room * currentPlayerPosition);

};

#endif