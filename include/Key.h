#ifndef KEY_H
#define KEY_H

#include "../include/Items.h"

class Key : public Items{

    private:
        string nameOfRoomOpened;

    public:
    
    //constructors
        Key(); 
        Key(string nameOfRoomOpened, string name, string description);

    //setter
        void setNameOfRoomOpened(string n);

    //getter
        string getNameOfRoomOpened();

};

#endif