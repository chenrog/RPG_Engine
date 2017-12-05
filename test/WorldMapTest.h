//
// Created by whyar on 12/4/2017.
//

#ifndef CS3520_2017FA_PROJ_GAMESTATE_H
#define CS3520_2017FA_PROJ_GAMESTATE_H

#include "../src/model/World/WorldMap.h"

#include <cxxtest/TestSuite.h>

//LINKER: ../src/model/World/WorldMap.cpp

class WorldMapTest : public CxxTest::TestSuite {
public:

    void testConstructor() {
        WorldMap * wm = new WorldMap(4);
        TS_ASSERT_EQUALS(wm->getCurEnemiesSize(), 0);
    }
};


#endif //CS3520_2017FA_PROJ_GAMESTATE_H
