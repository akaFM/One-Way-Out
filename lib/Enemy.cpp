#include "Enemy.h"

Enemy::Enemy(string name, int health, int damage, string weakness){
    this->name = name;
    this->health = health;
    this->damage = damage;
    this->weakness = weakness;
}

void Enemy::subtractHealth(int damageEnemy, string weak){
    if(weak == weakness){
        damageEnemy *= 1.5;
    }
    this->health -= damageEnemy;
    
}
//getter 
int Enemy::damagePlayer(){
    return damage;
}

void Enemy::setWeakness(string weak){
    weakness = weak;
}

void Enemy::damageEnemy(int dam){
    health -= dam;
}