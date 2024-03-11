#ifndef ROOM_H
#define ROOM_H

#include <string>

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

    public:

        Room();
        Room(const std::string& name, const std::string& description, bool locked);

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

        //todo: room inventory


};

#endif