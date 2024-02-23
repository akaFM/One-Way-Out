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

    public:

        Room();
        Room(const std::string& name, const std::string& description, bool locked);

        const std::string getName() const;
        const std::string getDescription() const;
        const bool isLocked() const;

        Room * getRoomToNorth();
        Room * getRoomToSouth();
        Room * getRoomToEast();
        Room * getRoomToWest();

};

#endif