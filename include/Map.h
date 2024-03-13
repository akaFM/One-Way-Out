#ifndef MAP_H
#define MAP_H

#include "Room.h"

class Map {

    private:
        Room * gameMap[4][5]; //fixed size, four rows five columns
        Room * playerPosition; 
    public:
        Map();
        void initializeGameMap();
        Room * getPlayerPosition();
        void moveDirection(const std::string direction);
        void printCurrentRoomInfo();

};

#endif