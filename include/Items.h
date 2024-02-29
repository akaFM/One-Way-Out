#ifndef ITEMS_H
#define ITEMS_H


#include <string>
#include <iostream>
using namespace std;

class Items {

    private:
        string name;
        string description;
        string type; 

    public:
    
    //constructors
        Items() : name(""), description(""), type("")
        {}
        Items(string n, string d, string t) : name(n), description(d), type(t)
        {}

    //setter functions
        void setName(string n);
        void setDescription(string d);
        void setType(string t);

    //getter functions
        string getName();
        string getDescription();
        string getType(); 

};

#endif