#ifndef ITEMS_H
#define ITEMS_H


#include <string>
#include <iostream>
using namespace std;

class Items {

    private:
        string name;
        string description;
        int type;  //0 means nothing 1 is consumable 2 is weapon 3 is for a key
                   // 1st constructor will randomly assign 0-3 into type so 
                   //what you get is randomized 
    public:
    
    //constructors
        Items();
        Items(string n, string d, int t);
    //setter functions
        void setName(string n);
        void setDescription(string d);
        void setType(int t);

    //getter functions
        string getName();
        string getDescription();
        int getType(); 

        bool itemExists();
        void deleteItem();

};

#endif