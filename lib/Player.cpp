#include "../include/Player.h"
#include "../include/Room.h"
#include "../include/Items.h"
#include "../include/Key.h"
#include "../include/Consumables.h"
#include <stdexcept>
using namespace std;

Player::Player(int difficulty){
    
    if (difficulty == 1) { //case easy
        // placeholder
        health = 100;
        stepsRemaining = 40;
    } 
    else if (difficulty == 2) { //case hard
        // placeholder
        health = 100;
        stepsRemaining = 28;
    }
    else { //case invalid
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
    if (stepsRemaining <= 0){
        cout << "Your legs gave out and you collapsed onto the floor!\nGAME OVER!\n" << endl; 
        endGame();
    }
}


const int Player::hasItem(string itemName) {
    
    for (unsigned int j = 0; j < inventory.size(); ++j) {
        if (itemName == inventory.at(j).getName()) {
            return j;
        }
    }
    return -1;

}

void Player::removeItem(string itemName){

    for (unsigned int j = 0; j < inventory.size(); ++j) {
        if (itemName == inventory.at(j).getName()) {
            inventory.erase(inventory.begin() + j);
            return; 
        }
    }

    cout << "\nDEVELOPMENT ERROR: You couldn't remove the [" << itemName << "] because you don't have one!\n" << endl; 

}

void Player::addItem(Items itemToAdd){
    inventory.push_back(itemToAdd);
}

const bool Player::isInventoryEmpty() {
    return inventory.empty();
}

void Player::deductItemFromInventory(const string itemName, Room* currRoom) {

    // -1 if item isn't in inventory, otherwise, returns index of the item
    const int itemIndex = hasItem(itemName);

    // player is not in possession of item they want to drop
    if(itemIndex == -1){cout << "\nYou don't have that." << endl; return;}
        
    // otherwise...
    currRoom->addItemToRoom(inventory.at(itemIndex)); // add item to room inventory
    inventory.erase(inventory.begin() + itemIndex); // remove item from inventory
    cout << "\nYou dropped the " << itemName << ".\n" << endl; // dialogue prompt

}

void Player::takeItemFromRoom(const string itemName, Room * currRoom) {
    
    // the sought item does not exist in the room.
    if(currRoom->existsInRoom(itemName) == -1){cout << "\nThere is no " << itemName << " in this room!\n" << endl; return;}

    // the item exists in the room, remove it from the room and add to inventory
    inventory.push_back(currRoom->removeItemFromRoom(itemName));

}

void Player::examineItem(const string itemName){

    // check if you have the item.
    const int itemIndex = hasItem(itemName);

    // if you don't have the item, display dialogue and abort.
    if(itemIndex == -1){cout << "\nYou don't have that." << endl; return;}

    //if you do have the item, display information about it
    cout << "\nYou examine the " << itemName << "..." << endl;
    cout << "Name: " << inventory.at(itemIndex).getName() << endl;
    cout << "Description: " << inventory.at(itemIndex).getDescription() << "\n" << endl;

}

void Player::printInventory(){

    // inventory empty
    if(inventory.size() == 0){
        cout << "\nYou have nothing in your inventory!\n" << endl;
        return;
    }

    cout << "\nInventory: [";
    for(int j = 0; j < inventory.size() - 1; ++j){
        cout << inventory.at(j).getName() << ", ";
    }
    cout << inventory.at(inventory.size()-1).getName() << "]\n" << endl;

}

void Player::findAndUseItem(const string itemName, Room * currentPlayerPosition){
    const int itemLocation = hasItem(itemName);
    if(itemLocation != -1){

        useItem(inventory.at(itemLocation), currentPlayerPosition);
        return;

    }
    cout << "\nYou don't have that!\n" << endl;
}

void Player::useItem(Items itemToUse, Room * currentPlayerPosition){


    if((itemToUse.getName() == "paperclip" || itemToUse.getName() == "bobby pin") and (hasItem("paperclip") != -1 and hasItem("bobby pin") != -1)){ //crafting paperclip
        Key lockpick("Locker Room", "lockpick", "A makeshift lockpicking tool. You feel like you can use this for something...");
        addItem(lockpick);
        removeItem("bobby pin");
        removeItem("paperclip");
        cout << "\nYou used the paperclip and bobby pin to craft a lockpick!\n" << endl;
        return;
    }
    else if(itemToUse.getName() == "lockpick" and currentPlayerPosition->getName() == "Indoor Pool" and currentPlayerPosition->getNorthRoom()->isLocked()){ //unlocking locker room
        currentPlayerPosition->getNorthRoom()->setLocked(false);
        removeItem("lockpick");
        cout << "\nYou unlocked the Locker Room, but your lockpick broke!\n" << endl;
    }
    else if(itemToUse.getName() == "flashlight" and currentPlayerPosition->getName() == "Kitchen" and currentPlayerPosition->getWestRoom()->isLocked()){ //unlocking meat locker
        currentPlayerPosition->getWestRoom()->setLocked(false);
        cout << "\nYou shine your flashlight into the meat locker, illuminating the way!\n" << endl;
    }
    else if(itemToUse.getName() == "janitor's keys" and currentPlayerPosition->getName() == "Main Hallway 3" and currentPlayerPosition->getSouthRoom()->isLocked()){
        currentPlayerPosition->getSouthRoom()->setLocked(false);
        cout << "\nYou unlocked the janitor's closet!\n" << endl;
    }
    else if(itemToUse.getName() == "crowbar" and currentPlayerPosition->getName() == "Main Lobby"){ //case: win the game!!
        cout << "\nYou pried open the hotel entrance and ran out, feeling the fresh air fill your lungs!\n" << endl;
        cout << "YOU WIN!\nThank you for playing!\n" << endl;
        endGame();
    }
    else{
        cout << "\nUsing this item doesn't seem to accomplish anything- at least not in this time or place.\n" << endl;
    }

}

void Player::eatConsumable(Consumables consumable){
    addSteps(consumable.getChangeHP());
    removeItem(consumable.getName());
}

void Player::addSteps(const int stepsToAdd){
    stepsRemaining += stepsToAdd; 
}