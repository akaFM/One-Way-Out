#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "Items.h"

class Room {

    private:
        
        std::string name;
        std::string description;
        bool locked;

        Room * roomToNorth;
        Room * roomToSouth;
        Room * roomToEast;
        Room * roomToWest;

        //todo: room inventory
        vector<Items> roomInventory;

    public:

        Room();
        Room(const std::string& name, const std::string& description, bool locked);
        Room(const std::string& name, const std::string& description, bool locked, vector<Items> roomInventory);

        const std::string getName() const;
        const std::string getDescription() const;
        const bool isLocked() const;
        void setLocked(const bool);

        Room * getNorthRoom();
        Room * getSouthRoom();
        Room * getEastRoom();
        Room * getWestRoom();

        void setNorthRoom(Room *);
        void setSouthRoom(Room *);
        void setEastRoom(Room *);
        void setWestRoom(Room *);

        // returns the index of an item in roomInventory if it exists
        // otherwise, returns -1
        const int existsInRoom(const string itemName);
    
        // removes an item from a room's inventory and returns the item
        Items removeItemFromRoom(const string itemName);
        void addItemToRoom(Items item);
        void printRoomInventory();

};

#endif