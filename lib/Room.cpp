#include "../include/Map.h"
#include "../include/Room.h"
#include "../include/Items.h"
#include <string>
#include <iostream>
#include <vector>
#include "../include/Items.h"
#include "../include/Enemy.h"

using namespace std;

// default constructor (empty everything, no directional pointers, unlocked)
Room::Room(){

    this->name = "";
    this->description = "";
    this->locked = false;

    this->roomToNorth = nullptr;
    this->roomToSouth = nullptr;
    this->roomToEast = nullptr;
    this->roomToWest = nullptr;

}

// custom constructor for room without items
Room::Room(const std::string& name, const std::string& description, bool locked){
    this->name = name;
    this->description = description;
    this->locked = locked;
}

// custom constructor for room with items
Room::Room(const std::string& name, const std::string& description, bool locked, vector<Items> roomInventory){
    this->name = name;
    this->description = description;
    this->locked = locked;
    this->roomInventory = roomInventory; 
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

// removes an item from roomInventory if it exists, and returns the item that was removed
Items Room::removeItemFromRoom(const string itemName){
    const int indexOfItem = existsInRoom(itemName);

    // note: there is no need to make sure that the item exists in the roomInventory
    // because the only place this is called is in takeItemFromRoom() in the Player class,
    // which will already check for us.

    Items i = roomInventory.at(indexOfItem);
    roomInventory.erase(roomInventory.begin() + indexOfItem);
    cout << "\n" << itemName << " removed from the room.\n" << endl;
    return i;

}

void Room::addItemToRoom(Items item){
    roomInventory.push_back(item);
    cout << item.getName() << " added to room inventory." << endl;
}

void Room::printRoomInventory(){

    int inventorySize = roomInventory.size();
    
    if(inventorySize == 0){cout << "\nThis room contains no items.\n" << endl; return;}

    cout << "\nThis room contains the following items: [";
    for(int j = 0; j < inventorySize - 1; ++j){
        cout << roomInventory.at(j).getName() << ",";
    }
    cout << roomInventory.at(inventorySize-1).getName() << "]\n" << endl;

}
