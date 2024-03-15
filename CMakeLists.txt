CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
project(FinalProjectItemsTest)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test
    lib/Items.cpp
    # lib/Consumables.cpp
    # lib/Weapon.cpp
    # lib/Key.cpp
    test/ItemTests.cpp
    #test/ConsumableTests.cpp
    # test/WeaponTests.cpp 
    # test/KeyTests.cpp
)

TARGET_LINK_LIBRARIES(test gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
