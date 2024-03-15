#include "../include/Map.h"
#include "../include/Room.h"
#include "../include/Items.h"
#include "../include/Consumables.h"
#include "../include/Key.h"
#include "../include/Weapon.h"
#include <string>
#include <iostream>
#include <vector>

Map::Map(){
    initializeGameMap();
}

Map::~Map() {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            delete gameMap[i][j];
            gameMap[i][j] = nullptr;
        }
    }
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
        Items note("note", "A note that reads the following: 'Did you know you can just use the first letter of a command instead of typing the whole command out? Additionally, instead of using the 'go' command, just state your direction! Maybe this will save you some time... you definitely need it.'\nWay to break the fourth wall, you think to yourself...\n");
        roomOneInventory.push_back(note);


    // ROOM INITIALIZATION
    gameMap[3][3] = new Room("Hotel Room", "A trashed hotel room; unfolded laundry all over the place. Only the door in front of you leads out.", false, roomOneInventory); // this is the spawn room
    gameMap[2][3] = new Room("Main Hallway 1", "The formerly luxurious hallway is covered in dust. The lights are flickering. The hallway continues to your left, and there is a door to your right.", false); 
    gameMap[2][2] = new Room("Main Hallway 2", "The hallway stretches on to your left and right, dimly lit. There is a door in front of you, labeled 'Cafeteria.' Some lunch doesn't sound so bad.", false);
    gameMap[2][1] = new Room("Main Hallway 3", "This portion of the hallway is much darker. There are cobwebs all over the place. You can return east into a more familiar area, open the door to your south, or head west toward the indoor pool.", false);
    gameMap[2][0] = new Room("Indoor Pool", "The pool is completely empty! A good swim would've been perfect right now. You can head eastward into the main hallway, or explore the locker room to your north.", false);
    gameMap[3][1] = new Room("Janitor Closet", "Northing too special in here, just a bunch of mops and janitorial equipment. Maybe something in here could be useful. You can head north back into the main hallway.", false);
    gameMap[1][0] = new Room("Locker Room", "The floor is all wet. Some of the lockers are wide open. You can head south, back to the pool area, when you're ready.", false);
    gameMap[1][2] = new Room("Cafeteria", "The cafeteria isn't actually in such terrible condition. You wonder whether you should sit down for a while, or move north into the kitchen. The door to the main hallway remains open behind you.", false);
    gameMap[0][2] = new Room("Kitchen", "Unlike the cafeteria, this kitchen is disgusting. Normally, you wouldn't even consider eating food from here, but maybe desperate times call for desperate measures. You can try to enter the meat locker to your left, or head south the the cafeteria.", false);
    gameMap[0][1] = new Room("Meat Locker", "It's freezing in here. The stench of expired poultry floods your nostrils. You immediately feel compelled to leave via the door to your east, but maybe you'll do some searching first.", false);
    gameMap[2][4] = new Room("Stairwell", "You enter a dark stairwell. The lights are flickering. The door to the main lobby is down a flight of stairs to your north, and a door to your west that leads back to the hallway.", false);
    gameMap[1][4] = new Room("Main Lobby", "The hotel's main entrance is boarded off! It looks like someone tried to trap you in here. You've got to get out. The door to your south leads back to the stairwell.", false);

    this->playerPosition = gameMap[3][3]; //set spawn location

    // room 1 connections
    gameMap[3][3]->setNorthRoom(gameMap[2][3]);
    gameMap[3][3]->setSouthRoom(nullptr);
    gameMap[3][3]->setWestRoom(nullptr);
    gameMap[3][3]->setEastRoom(nullptr);

    // room 2 connections
    gameMap[2][3]->setNorthRoom(nullptr);
    gameMap[2][3]->setSouthRoom(gameMap[3][3]);
    gameMap[2][3]->setWestRoom(gameMap[2][2]);
    gameMap[2][3]->setEastRoom(gameMap[2][4]);

    // room 3 connections
    gameMap[2][2]->setNorthRoom(gameMap[1][2]);
    gameMap[2][2]->setSouthRoom(nullptr);
    gameMap[2][2]->setWestRoom(gameMap[2][1]);
    gameMap[2][2]->setEastRoom(gameMap[2][3]);

    // room 4 connections
    gameMap[2][1]->setNorthRoom(nullptr);
    gameMap[2][1]->setSouthRoom(gameMap[3][1]);
    gameMap[2][1]->setWestRoom(gameMap[2][0]);
    gameMap[2][1]->setEastRoom(gameMap[2][2]);

    // room 5 connections
    gameMap[2][0]->setNorthRoom(gameMap[1][0]);
    gameMap[2][0]->setSouthRoom(nullptr);
    gameMap[2][0]->setWestRoom(nullptr);
    gameMap[2][0]->setEastRoom(gameMap[2][1]);

    // room 6 connections
    gameMap[3][1]->setNorthRoom(gameMap[2][1]);
    gameMap[3][1]->setSouthRoom(nullptr);
    gameMap[3][1]->setWestRoom(nullptr);
    gameMap[3][1]->setEastRoom(nullptr);

    // room 7 connections
    gameMap[1][0]->setNorthRoom(nullptr);
    gameMap[1][0]->setSouthRoom(gameMap[2][0]);
    gameMap[1][0]->setWestRoom(nullptr);
    gameMap[1][0]->setEastRoom(nullptr);

    // room 8 connections
    gameMap[1][2]->setNorthRoom(gameMap[0][2]);
    gameMap[1][2]->setSouthRoom(gameMap[2][2]);
    gameMap[1][2]->setWestRoom(nullptr);
    gameMap[1][2]->setEastRoom(nullptr);

    // room 9 connections
    gameMap[0][2]->setNorthRoom(nullptr);
    gameMap[0][2]->setSouthRoom(gameMap[1][2]);
    gameMap[0][2]->setWestRoom(gameMap[0][1]);
    gameMap[0][2]->setEastRoom(nullptr);

    // room 10 connections
    gameMap[0][1]->setNorthRoom(nullptr);
    gameMap[0][1]->setSouthRoom(nullptr);
    gameMap[0][1]->setWestRoom(nullptr);
    gameMap[0][1]->setEastRoom(gameMap[0][2]);

    // room 11 connections
    gameMap[2][4]->setNorthRoom(gameMap[1][4]);
    gameMap[2][4]->setSouthRoom(nullptr);
    gameMap[2][4]->setWestRoom(gameMap[2][3]);
    gameMap[2][4]->setEastRoom(nullptr);

    // room 12 connections
    gameMap[1][4]->setNorthRoom(nullptr);
    gameMap[1][4]->setSouthRoom(gameMap[2][4]);
    gameMap[1][4]->setWestRoom(nullptr);
    gameMap[1][4]->setEastRoom(nullptr);

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
    else if(direction == ""){
        std::cout << "\nGo where?\n" << std::endl;
        return;
    } else {
        std::cout << "\nYou can only go north, south, east, or west.\n" << std::endl;
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
