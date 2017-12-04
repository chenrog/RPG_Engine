//
// Created by whyar on 12/4/2017.
//

#ifndef CS3520_2017FA_PROJ_WORLDTEST_H
#define CS3520_2017FA_PROJ_WORLDTEST_H

#include "../src/model/World/World.h"
#include "../src/model/Item/item.h"

#include <cxxtest/TestSuite.h>

class WorldTest : public CxxTest::TestSuite {

    testConstructor() {
        World * world = new World();
        TS_ASSERT_EQUALS(world.getWorldMap().getWorldMap().size(), 30);
        TS_ASSERT_EQUALS(world.getWorldMap().getWorldMap()[0].size(), 30);
        TS_ASSERT_EQUALS(world.getPlayer().getName(), "Twen");
        TS_ASSERT_EQUALS(world.curMenuOption, 0);
        TS_ASSERT_EQUALS(world.getCurrentGameState(), OVERWORLD);

    }

    testMovePlayer() {
        TS_ASSERT_EQUALS(world.getPlayer().getPosition().getX(), 0);
        TS_ASSERT_EQUALS(world.getPlayer().getPosition().getY(), 0);
        World * world = new World();
        world.movePlayer(RIGHT, 1);
        TS_ASSERT_EQUALS(world.getPlayer().getPosition().getX(), 1);
        TS_ASSERT_EQUALS(world.getPlayer().getPosition().getY(), 0);
    }

    testAddToInventory() {
        Item * item = new Item("IT", "EM");
        Item * meti = new Item("Back", "Wards");
        World world = new World();
        world.addToInventory(item);
        TS_ASSERT_EQUALS(world.getInventory()[0].getName(), "IT");
        world.addToInventory(meti);
        TS_ASSERT_EQUALS(world.getInventory()[1].getName(), "Back");
    }


};

#endif //CS3520_2017FA_PROJ_WORLDTEST_H
