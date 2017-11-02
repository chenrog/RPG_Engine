//
// Created by whyar on 12/2/2017.
//

#ifndef CS3520_2017FA_PROJ_MAPCELLTEST_H
#define CS3520_2017FA_PROJ_MAPCELLTEST_H

#include "../src/model/World/MapCell.h"
#include <cxxtest/TestSuite.h>

#include <iostream>

class MapCellTest {

    void testMapCellConstructor(){
        MapCell c1 = MapCell(Point(0,0), true);
        TS_ASSERT_EQUALS(c1.getPosition().getX(), 0);
        TS_ASSERT_EQUALS(c1.getPosition().getY(), 0);
        TS_ASSERT_EQUALS(c1.isWalkable(), true);
        TS_ASSERT_EQUALS(c1.isRandomEncounterable(), true);
        TS_ASSERT_EQUALS()
    }

};


#endif //CS3520_2017FA_PROJ_MAPCELLTEST_H
