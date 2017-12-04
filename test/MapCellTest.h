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
        Posn *p1 = new Posn(0, 0);
        MapCell c1 = MapCell(p1, false);
        TS_ASSERT_EQUALS(c1.getPosition().getX(), 0);
        TS_ASSERT_EQUALS(c1.getPosition().getY(), 0);
        TS_ASSERT_EQUALS(c1.isWalkable(), false);
        TS_ASSERT_EQUALS(c1.isRandomEncounterable(), false);
        TS_ASSERT_EQUALS(c1.getEntity(), nullptr);
        delete p1;

    }

    void testMapCell2() {
        Posn *p1 = new Posn(2, 5);
        MapCell c1 = MapCell(p1, true);
        TS_ASSERT_EQUALS(c1.getPosition().getX(), 2);
        TS_ASSERT_EQUALS(c1.getPosition().getY(), 5);
        TS_ASSERT_EQUALS(c1.isWalkable(), true);
        TS_ASSERT_EQUALS(c1.isRandomEncounterable(), false);
        TS_ASSERT_EQUALS(c1.getEntity(), nullptr);
        delete p1;

    }

    void testMapCell3() {
        Posn *p1 = new Posn(10, 20);
        MapCell c1 = MapCell(p1, true);
        TS_ASSERT_EQUALS(c1.getPosition().getX(), 10);
        TS_ASSERT_EQUALS(c1.getPosition().getY(), 20);
        TS_ASSERT_EQUALS(c1.isWalkable(), true);
        TS_ASSERT_EQUALS(c1.isRandomEncounterable(), false);
        c1.setRandomEncounters(true);
        TS_ASSERT_EQUALS(c1.isRandomEncounterable(), true);
        delete p1;

    }

    void testMapCell4() {
        Posn *p1 = new Posn(4, 2);
        Item *i1 = new Item("item 1", "item description");
        MapCell c1 = MapCell(p1, i1, true);
        TS_ASSERT_EQUALS(c1.getPosition().getX(), 4);
        TS_ASSERT_EQUALS(c1.getPosition().getY(), 2);
        TS_ASSERT_EQUALS(c1.isWalkable(), true);
        TS_ASSERT_EQUALS(c1.isRandomEncounterable(), false);
        TS_ASSERT_EQUALS(dynamic_cast<Item *>(c1.getEntity())->getName(), "item 1");
        TS_ASSERT_EQUALS(dynamic_cast<Item *>(c1.getEntity())->getName(), "item description");
        delete p1;
    }

    void testMapCell5() {
        Posn *p1 = new Posn(4, 2);
        Item *i1 = new Item("item 1", "item description");
        MapCell c1 = MapCell(p1, i1, true);
        TS_ASSERT_EQUALS(c1.getPosition().getX(), 4);
        TS_ASSERT_EQUALS(c1.getPosition().getY(), 2);
        TS_ASSERT_EQUALS(c1.isWalkable(), true);
        TS_ASSERT_EQUALS(c1.isRandomEncounterable(), false);
        TS_ASSERT_EQUALS(dynamic_cast<Item *>(c1.getEntity())->getName(), "item 1");
        TS_ASSERT_EQUALS(dynamic_cast<Item *>(c1.getEntity())->getDescription(), "item description");
        Item *i2 = new Item("item 2", "item description 2");
        c1.setEntity(*i2);
        TS_ASSERT_EQUALS(dynamic_cast<Item *>(c1.getEntity())->getName(), "item 2");
        TS_ASSERT_EQUALS(dynamic_cast<Item *>(c1.getEntity())->getDescription(), "item description 2");
        delete p1;
        delete 1l;
    }

    void testMapCell6() {
        Posn *p1 = new Posn(4, 2);
        NPCUnit *npcUnit = new NPCUnit(DIALOGUE, Posn(0, 0), "A", "HI");
        npcUnit->setPosition(*p1);
        MapCell c1 = MapCell(p1, npcUnit, true);
        TS_ASSERT_EQUALS(c1.getPosition().getX(), 4);
        TS_ASSERT_EQUALS(c1.getPosition().getY(), 2);
        TS_ASSERT_EQUALS(c1.isWalkable(), true);
        TS_ASSERT_EQUALS(c1.isRandomEncounterable(), false);
        TS_ASSERT_EQUALS(dynamic_cast<NPCUnit *>(c1.getEntity())->getName(), "A");
        TS_ASSERT_EQUALS(dynamic_cast<NPCUnit *>(c1.getEntity())->getDialogue(), "HI");
        delete npcUnit;
        delete p1;
    }
};


#endif //CS3520_2017FA_PROJ_MAPCELLTEST_H
