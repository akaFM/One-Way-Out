#include "../include/Map.h"
#include "../include/Room.h"
#include "../include/Items.h"
#include <string>
#include <iostream>

using namespace std;

Room::Room(){

    this->name = "";
    this->description = "";
    this->locked = false;

    this->roomToNorth = nullptr;
    this->roomToSouth = nullptr;
    this->roomToEast = nullptr;
    this->roomToWest = nullptr;

}

Room::Room(const std::string& name, const std::string& description, bool locked){
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

bool Room::itemInRoom(){ 
    Items a;
    return a.itemExists(); 
}

void Room::removeItem(){
    Items a;
    if(a.itemExists()){
        a.deleteItem();
    }
}

void Room::addItem(){
    Items a;
    if(a.itemExists()){
        cout << "Can't add anymore Items. Item capacity is at the limit!!" << endl;
    }
    else{
        int input; 
        cout << "Enter 1-3 for type of item: " << endl;
        cout << "1 for consumable " << endl;
        cout << "2 for weapon " << endl;
        cout << "3 for key " << endl;
        cout << "0 for add nothing " << endl;
        
        cin >> input;

        if(input == 1){
            Items("Consumable", "Heals", 1);
        }
        else if (input == 2){
            Items("Weapon", "Deals Dmg", 2);
        }
        else if (input == 3){
            Items("Key", "Opens rooms", 3);
        }
    }
}