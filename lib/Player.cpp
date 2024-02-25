#include "../include/Player.h"
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
        exit 1;
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

boolean Player::hasItem(Item i) {
    bool ownership;
    for (unsigned int j = 0; j < inventory.size(); ++j) {
        if (j == inventory.at(i)) {
            ownership = true;
            break;
        }
        ownership = false;
    }
    return ownership;
}

void Player::dropItem(Item i) {
    int dropIndex = 0;
    for (unsigned int j = 0; j < inventory.size(); ++j) {
        if (i == inventory.at(j)) {
            // drop item in the room player is currently in
            // room vect.pushback(i)
            dropIndex = j;
            // remove item from player inventory
            if (dropIndex < inventory.size()) {
                inventory.erase(inventory.begin() + j);
            }
        }
    }
}

void Player::giveItem(Item i) {
     for (unsigned int j = 0; j < inventory.size(); ++j) {
        //search for item index
     }
     // give item
}