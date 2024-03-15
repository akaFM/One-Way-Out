#include "gtest/gtest.h"
#include "../include/Items.h"
#include "../include/Weapon.h"



//CONSTRUCTOR TEST
TEST(WeaponTest, ConstructorTest){
    Weapon axe; 
    EXPECT_EQ(axe.getDamage(), 0);
    EXPECT_EQ(axe.getName(), "");
    EXPECT_EQ(axe.getDescription(), "");
}

TEST(WeaponTest, ConstructorTest2){
    Weapon axe(100, "Battle Axe", "Devastating Damage");
    EXPECT_EQ(axe.getDamage(), 100);
    EXPECT_EQ(axe.getName(), "Battle Axe");
    EXPECT_EQ(axe.getDescription(), "Devastating Damage");
}

TEST(WeaponTest, ConstructorTest3){
    Weapon axe(100, "Frying Pan", "1 Shots");
    EXPECT_EQ(axe.getDamage(), 100);
    EXPECT_EQ(axe.getName(), "Frying Pan");
    EXPECT_EQ(axe.getDescription(), "1 Shots");
}


//SETTERS TEST
TEST(WeaponTest, SetterTest1){
    Weapon axe;
    axe.setDamage(55);
    EXPECT_EQ(axe.getDamage(), 55);
}

TEST(WeaponTest, SetterTest2){
    Weapon axe;
    axe.setDamage(69);
    EXPECT_EQ(axe.getDamage(), 69);
}
