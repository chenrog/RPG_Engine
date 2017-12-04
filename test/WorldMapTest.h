//
// Created by whyar on 12/4/2017.
//

#ifndef CS3520_2017FA_PROJ_GAMESTATE_H
#define CS3520_2017FA_PROJ_GAMESTATE_H

#include "../src/model/World/WorldMap.h"

#include <cxxtest/TestSuite.h>


class WorldMapTest : public CxxTest::TestSuite {
public:

    testconstructor() {
        WorldMap wm = new WorldMap();
        TS_ASSERT_EQUALS(wm.getWorldMap().size(), 30);
        TS_ASSERT_EQUALS(wm.getWorldMap()[0].size(), 30);
    }
};


#endif //CS3520_2017FA_PROJ_GAMESTATE_H
