CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
project(FinalProjectItemsTest)

#ADD_SUBDIRECTORY(googletest)
# for when andrew's branch is merged

#ADD_EXECUTABLE(testEXE
    # lib/Items.cpp
    # lib/Consumables.cpp
    # lib/Weapon.cpp
    # lib/Key.cpp
    # test/ItemTests.cpp
    #test/ConsumableTests.cpp
    # test/WeaponTests.cpp 
    # test/KeyTests.cpp
#)

#TARGET_LINK_LIBRARIES(test gtest gtest_main)
#TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

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