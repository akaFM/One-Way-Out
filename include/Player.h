#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
using namespace std;

class Player {
    private: 
        vector<Item> inventory;
        int health;
        int stepsRemaining;
    public:
        Player(int Difficulty);
        //Health Attributes
        int getHealth();
        void setHealth(int hp);
        void deductHealth(int hp);

        //Steps ATtributes
        int getSteps();
        void deductSteps(int step);

        //Inventory Attributes
        boolean hasItem(Item i);
        void dropItem(Item i);
        void giveItem(Item i);
}