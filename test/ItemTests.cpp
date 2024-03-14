#include "gtest/gtest.h"
#include "../include/Items.h"


//CONSTRUCTOR TESTS
TEST(ItemsTest, ConstructorTest1){
    Items a;

    EXPECT_EQ(a.getName(), "");
    EXPECT_EQ(a.getDescription(), "");
}

TEST(ItemsTest, ConstructorTest2){
    Items a("fork", "can use for self defense", 2);

    EXPECT_EQ(a.getName(), "fork");
    EXPECT_EQ(a.getDescription(), "can use for self defense");
    EXPECT_EQ(a.getType(), 2);
}

//SETTER FUCNTIONS TESTS
TEST(ItemsTest, SetterFunctionTests1){
    Items a;
    a.setName("Apple");
    a.setDescription("Restores HP to full");
    a.setType(1);
    EXPECT_EQ(a.getName(), "Apple");
    EXPECT_EQ(a.getDescription(), "Restores HP to ful");
    EXPECT_EQ(a.getType(), 1);   
}

TEST(ItemsTest, SetterFunctionTests2){
    Items a;
    a.setName("Pan");
    a.setDescription("1 shots anything");
    a.setType(2);
    EXPECT_EQ(a.getName(), "Pan");
    EXPECT_EQ(a.getDescription(), "1 shots anything");
    EXPECT_EQ(a.getType(), 2);   
}

TEST(ItemsTest, SetterFunctionTests3){
    Items a;
    a.setName("Key");
    a.setDescription("Can Open Rooms");
    a.setType(3);
    EXPECT_EQ(a.getName(), "Key");
    EXPECT_EQ(a.getDescription(), "Can Open Rooms");
    EXPECT_EQ(a.getType(), 3);   
}

//Getter fucntions test
TEST(ItemsTest, GetterFunctionTest){
    Items a("Cock", "Crazed male Chicken. 1 shots enemies", 2);
    EXPECT_EQ(a.getName(), "Cock");
    EXPECT_EQ(a.getDescription(), "Crazed male Chicken. 1 shots enemies");
    EXPECT_EQ(a.getType(), 2);   
}

//TEST for ItemExits

TEST(ItemsTest, itemExistsTest1){
    Items a;
    EXPECT_EQ(a.itemExists(), 0);
}

TEST(ItemsTest, itemExistsTest2){
    Items a("Bone", "Craft material", 2);
    EXPECT_EQ(a.itemExists(), 1);
}

TEST(ItemsTest, deleteTest){
    Items a("Axe", "Dull axe. Ok for Chopping", 2);
    a.deleteItem();
    EXPECT_EQ(a.itemExists(), 1);
}