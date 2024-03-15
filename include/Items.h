#ifndef ITEMS_H
#define ITEMS_H


#include <string>
#include <iostream>
using namespace std;

class Items {

    private:
        string name;
        string description;
    public:

    //constructors
        Items();
        Items(string n, string d);

    //setter functions
        void setName(string n);
        void setDescription(string d);

    //getter functions
        string getName();
        string getDescription();

        bool itemExists();
        void deleteItem();

};

#endif