//
// Created by whyar on 12/2/2017.
//

#ifndef CS3520_2017FA_PROJ_MAPCELLTEST_H
#define CS3520_2017FA_PROJ_MAPCELLTEST_H

#include "../src/model/World/MapCell.h"
#include "../src/model/Item/Item.h"
#include "../src/model/Units/NPCUnit.h"
#include <cxxtest/TestSuite.h>

#include <iostream>

class MapCellTest {

    void testMapCell1() {
        MapCell c1 = MapCell(Posn(0, 0), false);
        TS_ASSERT_EQUALS(c1.getPosition().getX(), 0);
        TS_ASSERT_EQUALS(c1.getPosition().getY(), 0);
        TS_ASSERT_EQUALS(c1.isWalkable(), false);
        TS_ASSERT_EQUALS(c1.isRandomEncounterable(), false);
        TS_ASSERT_EQUALS(c1.getEntity(), nullptr);
    }

    void testMapCell2() {
        MapCell c1 = MapCell(Posn(2, 5), true);
        TS_ASSERT_EQUALS(c1.getPosition().getX(), 2);
        TS_ASSERT_EQUALS(c1.getPosition().getY(), 5);
        TS_ASSERT_EQUALS(c1.isWalkable(), true);
        TS_ASSERT_EQUALS(c1.isRandomEncounterable(), false);
        TS_ASSERT_EQUALS(c1.getEntity(), nullptr);
    }

    void testMapCell3() {
        MapCell c1 = MapCell(Posn(10, 20), true);
        TS_ASSERT_EQUALS(c1.getPosition().getX(), 10);
        TS_ASSERT_EQUALS(c1.getPosition().getY(), 20);
        TS_ASSERT_EQUALS(c1.isWalkable(), true);
        TS_ASSERT_EQUALS(c1.isRandomEncounterable(), false);
        c1.setRandomEncounters(true);
        TS_ASSERT_EQUALS(c1.isRandomEncounterable(), true);
    }

    void testMapCell4() {
        Item i1 = Item("item 1", "item description");
        MapCell c1 = MapCell(Posn(4, 2), i1, true);
        TS_ASSERT_EQUALS(c1.getPosition().getX(), 4);
        TS_ASSERT_EQUALS(c1.getPosition().getY(), 2);
        TS_ASSERT_EQUALS(c1.isWalkable(), true);
        TS_ASSERT_EQUALS(c1.isRandomEncounterable(), false);
        TS_ASSERT_EQUALS(dynamic_cast<Item *>(c1.getEntity())->getName(), "item 1");
        TS_ASSERT_EQUALS(dynamic_cast<Item *>(c1.getEntity())->getName(), "item description");
    }

    void testMapCell5() {
        Item i1 = Item("item 1", "item description");
        MapCell c1 = MapCell(Posn(4, 2), i1, true);
        TS_ASSERT_EQUALS(c1.getPosition().getX(), 4);
        TS_ASSERT_EQUALS(c1.getPosition().getY(), 2);
        TS_ASSERT_EQUALS(c1.isWalkable(), true);
        TS_ASSERT_EQUALS(c1.isRandomEncounterable(), false);
        TS_ASSERT_EQUALS(dynamic_cast<Item *>(c1.getEntity())->getName(), "item 1");
        TS_ASSERT_EQUALS(dynamic_cast<Item *>(c1.getEntity())->getDescription(), "item description");
        Item i2 = Item("item 2", "item description 2");
        c1.setEntity(i2);
        TS_ASSERT_EQUALS(dynamic_cast<Item *>(c1.getEntity())->getName(), "item 2");
        TS_ASSERT_EQUALS(dynamic_cast<Item *>(c1.getEntity())->getDescription(), "item description 2");
    }

    void testMapCell6() {
        NPCUnit npcUnit = NPCUnit(DIALOGUE, Posn(0, 0), "A", "HI");
        npcUnit.setPosition(Posn(4, 2));
        MapCell c1 = MapCell(Posn(4, 2), npcUnit, true);
        TS_ASSERT_EQUALS(c1.getPosition().getX(), 4);
        TS_ASSERT_EQUALS(c1.getPosition().getY(), 2);
        TS_ASSERT_EQUALS(c1.isWalkable(), true);
        TS_ASSERT_EQUALS(c1.isRandomEncounterable(), false);
        TS_ASSERT_EQUALS(dynamic_cast<NPCUnit *>(c1.getEntity())->getName(), "A");
        TS_ASSERT_EQUALS(dynamic_cast<NPCUnit *>(c1.getEntity())->getDialogue(), "HI");
    }
};


#endif //CS3520_2017FA_PROJ_MAPCELLTEST_H
