#include "../include/Map.h"
#include "../include/Room.h"
#include "../include/Items.h"
#include <string>
#include <iostream>
#include <vector>

Map::Map(){
    initializeGameMap();
}

void Map::initializeGameMap(){

    //initialize all gameMap 2D array slots to "nullptr"
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            gameMap[i][j] = nullptr;
        }
    }
    //additionally, make playerPosition nullptr
    this->playerPosition = nullptr;

    // ROOM INVENTORY INITIALIZATION
    vector<Items> roomOneInventory;
        Items testItem("testName", "testDescription", 0);
        roomOneInventory.push_back(testItem);


    // ROOM INITIALIZATION
    gameMap[3][3] = new Room("1name", "1desc", false, roomOneInventory); // this is the spawn room
    gameMap[2][3] = new Room("2name", "2desc", false); 
    gameMap[2][2] = new Room("3name", "3desc", false);
    gameMap[2][1] = new Room("4name", "4desc", false);
    gameMap[2][0] = new Room("5name", "5desc", false);
    gameMap[3][1] = new Room("6name", "6desc", false);
    gameMap[1][0] = new Room("7name", "7desc", false);
    gameMap[1][2] = new Room("8name", "8desc", false);
    gameMap[0][2] = new Room("9name", "9desc", false);
    gameMap[0][1] = new Room("10name", "10desc", false);
    gameMap[2][4] = new Room("11name", "11desc", false);
    gameMap[1][4] = new Room("12name", "12desc", false);

    this->playerPosition = gameMap[3][3]; //set spawn location

    // room 1 connections
    gameMap[3][3]->setNorthRoom(gameMap[2][3]);

    // room 2 connections
    gameMap[2][3]->setSouthRoom(gameMap[3][3]);
    gameMap[2][3]->setWestRoom(gameMap[2][2]);
    gameMap[2][3]->setEastRoom(gameMap[2][4]);

    // room 3 connections
    gameMap[2][2]->setNorthRoom(gameMap[1][2]);
    gameMap[2][2]->setWestRoom(gameMap[2][1]);
    gameMap[2][2]->setEastRoom(gameMap[2][3]);

    // room 4 connections
    gameMap[2][1]->setWestRoom(gameMap[2][0]);
    gameMap[2][1]->setEastRoom(gameMap[2][2]);
    gameMap[2][1]->setSouthRoom(gameMap[3][1]);

    // room 5 connections
    gameMap[2][0]->setNorthRoom(gameMap[1][0]);
    gameMap[2][0]->setEastRoom(gameMap[2][1]);

    // room 6 connections
    gameMap[3][1]->setNorthRoom(gameMap[2][1]); 

    // room 7 connections
    gameMap[1][0]->setSouthRoom(gameMap[2][0]);

    // room 8 connections
    gameMap[1][2]->setNorthRoom(gameMap[0][2]);
    gameMap[1][2]->setSouthRoom(gameMap[2][2]);

    // room 9 connections
    gameMap[0][2]->setSouthRoom(gameMap[1][2]);
    gameMap[0][2]->setWestRoom(gameMap[0][1]);

    // room 10 connections
    gameMap[0][1]->setEastRoom(gameMap[0][2]);

    // room 11 connections
    gameMap[2][4]->setNorthRoom(gameMap[1][4]);
    gameMap[2][4]->setWestRoom(gameMap[2][3]);

    // room 12 connections
    gameMap[1][4]->setSouthRoom(gameMap[2][4]);

    return;

}

Room* Map::getPlayerPosition(){
    return this->playerPosition;
}

void Map::moveDirection(const std::string direction){

    Room * tempRoomPointer = nullptr;

    if(direction == "north"){tempRoomPointer = playerPosition->getNorthRoom();}
    else if(direction == "south"){tempRoomPointer = playerPosition->getSouthRoom();}
    else if(direction == "east"){tempRoomPointer = playerPosition->getEastRoom();}
    else if(direction == "west"){tempRoomPointer = playerPosition->getWestRoom();}
    else{
        std::cout << "\nInvalid direction.\n" << std::endl;
        return; // this would only happen if commandParser calls moveDirection incorrectly
    }

    if(tempRoomPointer != nullptr){ // if the requested room exists
            if(tempRoomPointer->isLocked()){ // if the requested room exists, but is locked
                std::cout << "\nThat room is locked!\n" << std::endl;
            } else { // if the requested room exists, and is unlocked -> SUCCESS CASE
                playerPosition = tempRoomPointer;
                std::cout << "\nYou moved " << direction << "." << std::endl;
                printCurrentRoomInfo();
            }
    } else { // if the requested room does not exist
        std::cout << "\nYou cannot go that way!\n" << std::endl;
    }

    // note: tempRoomPointer ceases to exist upon function exit, but whatever is is pointing to will NOT be deleted. 

}

void Map::printCurrentRoomInfo(){
    std::cout << "\n" << playerPosition->getName() << std::endl;
    std::cout << playerPosition->getDescription();
    playerPosition->printRoomInventory();
}
