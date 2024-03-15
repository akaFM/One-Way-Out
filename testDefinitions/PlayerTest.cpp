#include <gtest/gtest.h>
#include "../include/Player.h"

TEST(Player, InitializePlayerConstructorEasyMode) {
    int difficulty = 1; //easy
    Player player1(difficulty);
    ASSERT_EQ(player1.getHealth(), 100);
    ASSERT_EQ(player1.getSteps(), 40);
    ASSERT_TRUE(player1.isInventoryEmpty());
}

TEST(Player, InitializePlayerConstructorHardMode) {
    int difficulty = 2; //hard
    Player player2(difficulty);
    ASSERT_EQ(player2.getHealth(), 100);
    ASSERT_EQ(player2.getSteps(), 20);
    ASSERT_TRUE(player2.isInventoryEmpty());
}

TEST(Player, setHealthTo1000) {
    int difficulty = 1;
    Player player(difficulty);
    player.setHealth(1000);
    ASSERT_GT(player.getHealth(), 100);
    ASSERT_EQ(player.getHealth(), 1000);
}

TEST(Player, deductHealthToZero) {
    int difficulty = 1;
    Player player(difficulty);
    player.deductHealth(player.getHealth());
    ASSERT_FALSE(player.getHealth() > 0);
    ASSERT_EQ(player.getHealth(), 0);
}

TEST(Player, playerTakeItemFromRoom) {
    int difficulty = 1;
    Player player(difficulty);
    vector<Items> itemsInRoom;
    Items item1("testItem1", "test item1");
    itemsInRoom.push_back(item1);
    Room adminRoom("adminRoom", "test room", false, itemsInRoom);
    player.takeItemFromRoom("testItem1", &adminRoom);                   
    EXPECT_EQ(adminRoom.existsInRoom("testItem1"), -1);
}

TEST(Player, playerDeductItemFromInventory) {
    int difficulty = 1;
    Player player(difficulty);
    vector<Items> itemsInRoom;
    Items item1("testItem1", "test item1");
    itemsInRoom.push_back(item1);
    Room adminRoom("adminRoom", "test room", false, itemsInRoom);
    player.takeItemFromRoom("testItem1", &adminRoom);
    player.deductItemFromInventory("testItem1", &adminRoom);               
    EXPECT_NE(adminRoom.existsInRoom("testItem1"), -1);
}

TEST(Player, playerExamineItem) {
    int difficulty = 1;
    Player player(difficulty);
    testing::internal::CaptureStdout();
    player.examineItem("Apple");
    string outputDoesNotHaveItem = testing::internal::GetCapturedStdout();
    EXPECT_EQ(outputDoesNotHaveItem.find("You examine the Apple."), string::npos);
    vector<Items> itemsInRoom;
    Items item1("testItem1", "test item1");
    itemsInRoom.push_back(item1);
    Room adminRoom("adminRoom", "test room", false, itemsInRoom);
    player.takeItemFromRoom("testItem1", &adminRoom);
    testing::internal::CaptureStdout();
    player.examineItem("testItem1");
    string outputPlayerHasItem = testing::internal::GetCapturedStdout();
    EXPECT_NE(outputPlayerHasItem.find("You examine the testItem1..."), string::npos);
}

TEST(Player, playerPrintInventory) {
    int difficulty = 1;
    Player player(difficulty);
    testing::internal::CaptureStdout();
    player.printInventory();
    string outputDoesNotHaveItem = testing::internal::GetCapturedStdout();
    EXPECT_NE(outputDoesNotHaveItem.find("You have nothing in your inventory!"), string::npos);

    vector<Items> itemsInRoom;
    Items item1("testItem1", "test item1");
    Items item2("testItem2", "test item2");
    Items item3("testItem3", "test item3");
    itemsInRoom.push_back(item1);
    itemsInRoom.push_back(item2);
    itemsInRoom.push_back(item3);
    Room adminRoom("adminRoom", "test room", false, itemsInRoom);
    player.takeItemFromRoom("testItem1", &adminRoom);
    player.takeItemFromRoom("testItem2", &adminRoom);
    player.takeItemFromRoom("testItem3", &adminRoom);
    testing::internal::CaptureStdout();
    player.printInventory();
    string outputPlayerInventory = testing::internal::GetCapturedStdout();
    EXPECT_NE(outputPlayerInventory.find("Inventory: [testItem1,testItem2,testItem3]"), string::npos);
}

