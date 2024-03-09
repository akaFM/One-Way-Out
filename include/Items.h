#ifndef ITEMS_H
#define ITEMS_H


#include <string>
#include <iostream>
using namespace std;

class Items {

    private:
        string name;
        string description;
        int weight;

    public:
        Items() : name(""), description(""), weight(0){}
        string getName(){ return name;};
        string getDescription(){return description;};
        int weight(){return weight;};
        
        //void useItem(Room*, Player); 


};

#endif