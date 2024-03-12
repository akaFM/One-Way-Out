#include "../include/Map.h"
#include "../include/Room.h"
#include "../include/Items.h"
#include <string>
#include <iostream>
#include <vector>
#include "Items.h"

using namespace std;

Room::Room(){

    this->name = "";
    this->description = "";
    this->locked = false;

    this->roomToNorth = nullptr;
    this->roomToSouth = nullptr;
    this->roomToEast = nullptr;
    this->roomToWest = nullptr;

    // roomInventory is empty by default

}

Room::Room(const std::string& name, const std::string& description, bool locked, vector<Items> roomInventory){
    this->name = name;
    this->description = description;
    this->locked = locked;
}

const std::string Room::getName() const {
    return this->name;
}

const std::string Room::getDescription() const {
    return this->description;
}

const bool Room::isLocked() const{
    return this->locked;
}

void Room::setLocked(const bool status){
    this->locked = status;
}

// getters and setters for directional pointers

Room * Room::getNorthRoom(){
    return this->roomToNorth;
}

Room * Room::getSouthRoom(){
    return this->roomToSouth;
}

Room * Room::getEastRoom(){
    return this->roomToEast;
}

Room * Room::getWestRoom(){
    return this->roomToWest;
}

void Room::setNorthRoom(Room * newNorthRoom){
    this->roomToNorth = newNorthRoom;
}

void Room::setSouthRoom(Room * newSouthRoom){
    this->roomToSouth = newSouthRoom;
}

void Room::setEastRoom(Room * newEastRoom){
    this->roomToEast = newEastRoom;
}

void Room::setWestRoom(Room * newWestRoom){
    this->roomToWest = newWestRoom;
}

// returns the index of an item in roomInventory if it exists
// otherwise, returns -1
const int Room::existsInRoom(const string itemName){ 
    for(unsigned i = 0; i < roomInventory.size(); ++i){
        if(roomInventory.at(i).getName() == itemName){
            return i;
        }
    }
    return -1;
}

void Room::removeItemFromRoom(const string itemName){
    const int indexOfItem = existsInRoom(itemName);
    if(indexOfItem == -1){
        cout << "\n There isn't a " << itemName << " in this room!" << endl;
        return;
    }
    roomInventory.erase(roomInventory.begin() + indexOfItem);
    cout << "\n" << itemName << " removed from the room.\n" << endl;
}

void Room::addItemToRoom(Items item){
    roomInventory.push_back(item);
    cout << "\n You dropped the " << item.getName() << "." << endl;
}