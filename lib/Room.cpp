#include "../include/Map.h"
#include "../include/Room.h"
#include <string>

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


//these are getters for the directional pointers. i chose to encapsulate them because
//it felt more neat that way.

Room * Room::getRoomToNorth(){
    return this->roomToNorth;
}

Room * Room::getRoomToSouth(){
    return this->roomToSouth;
}

Room * Room::getRoomToEast(){
    return this->roomToEast;
}

Room * Room::getRoomToWest(){
    return this->roomToWest;
}