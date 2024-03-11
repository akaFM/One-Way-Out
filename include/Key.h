#ifndef KEY_H
#define KEY_H

#include "../include/Items.h"

class Key : public Items{

    private:
        string condition;

    public:
    
    //constructors
        Key();

    //setter
        void setCondition(string c);

    //getter
        string getCondition();

};

#endif