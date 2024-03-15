#include "gtest/gtest.h"
#include "../include/Items.h"
#include "../include/Consumables.h"



//CONSTRUCTOR TESTS
TEST(ConsumableTest, ConstructorTest1){
    Consumables none; 
    EXPECT_EQ(none.getChangeHP(), 0);
    EXPECT_EQ(none.getConsumableType(), "");
}

TEST(ConsumableTest, ConstructorTest2){
    Consumables apple(100, "Food"); 
    EXPECT_EQ(apple.getChangeHP(), 100);
    EXPECT_EQ(apple.getConsumableType(), "Food");
}

//SETTER TESTS
TEST(ConsumableTest, SetterTest1){
    Consumables fish;
    fish.setChangeHP(50);
    fish.setConsumableType("Food");
    EXPECT_EQ(fish.getChangeHP(), 50);
    EXPECT_EQ(fish.getConsumableType(), "Food");
}