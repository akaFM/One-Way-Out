#include "gtest/gtest.h"
#include "../include/Items.h"
#include "../include/Weapon.h"



//CONSTRUCTOR TEST
TEST(WeaponTest, ConstructorTest){
    Weapon axe; 
    EXPECT_EQ(axe.getDamage(), 0);
    EXPECT_EQ(axe.getWeaponType(), "");
}

TEST(WeaponTest, ConstructorTest2){
    Weapon axe(100, "Melee");
    EXPECT_EQ(axe.getDamage(), 100);
    EXPECT_EQ(axe.getWeaponType(), "Melee");
}


//SETTERS TEST
TEST(WeaponTest, SetterTest1){
    Weapon axe;
    axe.setDamage(55);
    axe.setWeaponType("Melee");
    EXPECT_EQ(axe.getDamage(), 55);
    EXPECT_EQ(axe.getWeaponType(), "Melee");
}
