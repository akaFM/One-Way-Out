#ifndef ENEMY_H
#define ENEMY_H


#include <string>
#include <iostream>
using namespace std;

class Enemy {

    private:
        string name;
        int health;
        int damage;
        string weakness;


    public:
        Enemy() : name(""), health(0), damage(0), weakness(""){}
        Enemy(string, int, int, string);
        void subtractHealth(int, string);
        int damagePlayer();
        void setWeakness(string);
        void damageEnemy(int);

};

#endif