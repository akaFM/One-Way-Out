#include "../include/Map.h"
#include "../include/Room.h"
#include <string>

Map::Map(){
    initializeGameMap();
}

void Map::initializeGameMap(){

    //initialize all gameMap 2D array slots to "nullptr"
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            gameMap[i][j] = nullptr;
        }
    }

    //additionally, make playerPosition nullptr
    this->playerPosition = nullptr;

    //then, go through and put rooms where they are wanted.
    //directional pointers will be initialized after the fact.
    //NOTE: THESE ROOMS DO NOT CONTAIN ITEMS YET


}

Room* Map::getPlayerPosition(){
    return this->playerPosition;
}