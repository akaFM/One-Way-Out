CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
project(FinalProjectItemsTest)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(mainEXE
lib/CommandParser.cpp
lib/Consumables.cpp
lib/Enemy.cpp
lib/Items.cpp
lib/Key.cpp
lib/main.cpp
lib/Map.cpp
lib/Player.cpp
lib/Room.cpp
lib/Weapon.cpp
)

ADD_EXECUTABLE(runPlayerTests
testDefinitions/PlayerTest.cpp
lib/CommandParser.cpp
lib/Consumables.cpp
lib/Enemy.cpp
lib/Items.cpp
lib/Key.cpp
lib/Map.cpp
lib/Player.cpp
lib/Room.cpp
lib/Weapon.cpp
)

ADD_EXECUTABLE(runItemTests
    lib/Items.cpp
    lib/Consumables.cpp
    lib/Weapon.cpp
    lib/Key.cpp
    testDefinitions/ItemTests.cpp
    testDefinitions/ConsumableTests.cpp
    testDefinitions/WeaponTests.cpp 
    testDefinitions/KeyTests.cpp
)

TARGET_LINK_LIBRARIES(runPlayerTests gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(runPlayerTests PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(runItemTests gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(runItemTests PRIVATE gtest_disable_pthreads=ON)
