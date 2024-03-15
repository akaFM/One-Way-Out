#include "gtest/gtest.h"
#include "../include/Items.h"
#include "../include/Consumables.h"



//CONSTRUCTOR TESTS
TEST(ConsumableTest, ConstructorTest1){
    Consumables none; 
    EXPECT_EQ(none.getChangeHP(), 0);
}

TEST(ConsumableTest, ConstructorTest2){
    Consumables apple("apple", "Food", 100); 
    EXPECT_EQ(apple.getChangeHP(), 100);
}

//SETTER TESTS
TEST(ConsumableTest, SetterTest1){
    Consumables fish;
    fish.setChangeHP(50);
    EXPECT_EQ(fish.getChangeHP(), 50);
}