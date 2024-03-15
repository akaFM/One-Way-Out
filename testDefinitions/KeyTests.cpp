#include "gtest/gtest.h"
#include "../include/Items.h"
#include "../include/Key.h"



TEST(KeyTest, ConstructorTest1){
    Key flash;
    EXPECT_EQ(flash.getCondition(), "Great condition");
    EXPECT_EQ(flash.getName(), "Room Key");
    EXPECT_EQ(flash.getDescription(), "Can be used to open a door");
}

TEST(KeyTest, ConstructorTest2){
    Key flash("Oxidized", "Bronze Key", "Key is broken... Does Nothing");
    EXPECT_EQ(flash.getCondition(), "Oxidized");
    EXPECT_EQ(flash.getName(), "Bronze Key");
    EXPECT_EQ(flash.getDescription(), "Key is broken... Does Nothing");
}

TEST(KeyTest, ConstructorTest3){
    Key flash("Great condition", "Diamond Key", "Opens Everything");
    EXPECT_EQ(flash.getCondition(), "Great condition");
    EXPECT_EQ(flash.getName(), "Diamond Key");
    EXPECT_EQ(flash.getDescription(), "Opens Everything");
}

TEST(KeyTest, SetterTest1){
    Key ironKey;
    ironKey.setCondition("Broken");
    EXPECT_EQ(ironKey.getCondition(), "Broken");
}

TEST(KeyTest, SetterTest2){
    Key ironKey;
    ironKey.setCondition("Excellent");
    EXPECT_EQ(ironKey.getCondition(), "Excellent");
}