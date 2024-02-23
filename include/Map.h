#ifndef MAP_H
#define MAP_H

#include "Room.h"

class Map {

    private:
        Room * gameMap[5][4]; //fixed size
        Room * playerPosition; 
    public:
        Map();
        void initializeGameMap();
        Room * getPlayerPosition();

};

#endif