#include "../include/Player.h"
#include "../include/Room.h"
#include "../include/Items.h"
#include <stdexcept>
using namespace std;

Player::Player(int difficulty){
    // easy mode
    if (difficulty == 1) {
        // placeholder
        health = 2;
        stepsRemaining = 2;
    }

    // hard mode
    if (difficulty == 2) {
        // placeholder
        health = 1;
        stepsRemaining = 1;
    }

    // invalid difficulty
    else {
        throw invalid_argument("Invalid difficulty");
    }
}

int Player::getHealth() {
    return health;
}

void Player::setHealth(int hp) {
    health = hp; 
}

void Player::deductHealth(int hp) {
    health = health - hp;
}

int Player::getSteps() {
    return stepsRemaining;
}

void Player::deductSteps(int step) { 
    stepsRemaining = stepsRemaining - step;
}

bool Player::hasItem(Items item) {
    bool ownership;
    for (unsigned int j = 0; j < inventory.size(); ++j) {
        if (item.getName() == inventory.at(j).getName()) {
            ownership = true;
            break;
        }
        ownership = false;
    }
    return ownership;
}

void Player::deductItem(Items item, Room* currRoom) {
    size_t itemIndex = 0;
    for (unsigned int j = 0; j < inventory.size(); ++j) {
        if (item.getName() == inventory.at(j).getName()) {
            // drop item in the room player is currently in
            currRoom->addItem(item);
            // room vect.pushback(i)
            itemIndex = j;
            // remove item from player inventory
            if (itemIndex < inventory.size()) {
                inventory.erase(inventory.begin() + j);
                break;
            }
        }
    }
}

void Player::giveItem(Items item) {
    size_t itemIndex = 0;
     for (unsigned int j = 0; j < inventory.size(); ++j) {
        //search for item index
        //give item
        //remove item from player inventory
        if (itemIndex < inventory.size()) {
            inventory.erase(inventory.begin() + j);
        break;
        }
    }
}