#include "gtest/gtest.h"
#include "../include/Items.h"
#include "../include/Key.h"



TEST(KeyTest, ConstructorTest){
    Key flash;
    EXPECT_EQ(flash.getCondition(), "Great Condition. Key Works!");
}

TEST(KeyTest, SetterTest){
    Key ironKey;
    ironKey.setCondition("Rusted...Terrible Condition...Might Work");
    EXPECT_EQ(ironKey.getCondition(), "Rusted...Terrible Condition...Might Work");
}