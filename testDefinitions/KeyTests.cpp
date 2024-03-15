#include "gtest/gtest.h"
#include "../include/Items.h"
#include "../include/Key.h"



TEST(KeyTest, ConstructorTest1){
    Key flash;
    EXPECT_EQ(flash.getCondition(), "Great condition. Key Works!");
    EXPECT_EQ(flash.getName(), "Room Key");
    EXPECT_EQ(flash.getDescription(), "Can be used to open a door");
}

TEST(KeyTest, ConstructorTest2){
    Key flash("Broken Key", "Key is broken... Does Nothing", "Broken");
    EXPECT_EQ(flash.getCondition(), "Broken");
    EXPECT_EQ(flash.getName(), "Broken Key");
    EXPECT_EQ(flash.getDescription(), "Key is broken... Does Nothing");
}

TEST(KeyTest, ConstructorTest3){
    Key flash("Master", "You win the Game", "Great condition. Key Works!");
    EXPECT_EQ(flash.getCondition(), "Great condition. Key Works!");
    EXPECT_EQ(flash.getName(), "Master");
    EXPECT_EQ(flash.getDescription(), "You win the Game");
}

TEST(KeyTest, SetterTest){
    Key ironKey;
    ironKey.setCondition("Does not Work");
    EXPECT_EQ(ironKey.getCondition(), "Does not Work");
}