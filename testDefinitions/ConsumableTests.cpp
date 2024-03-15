#include "gtest/gtest.h"
#include "../include/Items.h"
#include "../include/Consumables.h"



//CONSTRUCTOR TESTS
TEST(ConsumableTest, ConstructorTest1){
    Consumables none; 
    EXPECT_EQ(none.getChangeHP(), 0);
    EXPECT_EQ(none.getName(), "");
    EXPECT_EQ(none.getDescription(), "");
}

TEST(ConsumableTest, ConstructorTest2){
    Consumables apple(100, "apple", "Heals"); 
    EXPECT_EQ(apple.getChangeHP(), 100);
    EXPECT_EQ(apple.getName(), "apple");
    EXPECT_EQ(apple.getDescription(), "Heals");
}

TEST(ConsumableTest, ConstructorTest3){
    Consumables strawberry(60, "strawberry", "Heals"); 
    EXPECT_EQ(strawberry.getChangeHP(), 60);
    EXPECT_EQ(strawberry.getName(), "strawberry");
    EXPECT_EQ(strawberry.getDescription(), "Heals");
}

//SETTER TESTS
TEST(ConsumableTest, SetterTest1){
    Consumables fish;
    fish.setChangeHP(50);
    EXPECT_EQ(fish.getChangeHP(), 50);
}

TEST(ConsumableTest, SetterTest2){
    Consumables fish;
    fish.setChangeHP(69);
    EXPECT_EQ(fish.getChangeHP(), 69);
}