//
// Created by whyar on 12/4/2017.
//

#ifndef CS3520_2017FA_PROJ_WORLDTEST_H
#define CS3520_2017FA_PROJ_WORLDTEST_H

#include "../src/model/World/World.h"
#include "../src/model/Item/Item.h"

#include <cxxtest/TestSuite.h>

//Linker: ../src/model/Spells/Spell.cpp ../src/model/Units/IEntity.cpp ../src/model/Units/AUnit.cpp ../src/model/Units/PlayerUnit.cpp  ../src/model/Units/NPCUnit.cpp  ../src/model/Units/EnemyUnit.cpp ../src/model/World/Posn.cpp ../src/model/World/MapCell.cpp ../src/model/Item/Equipment/Equipment.cpp ../src/model/Item/Item.cpp ../src/model/World/World.cpp ../src/model/World/WorldMap.cpp
class WorldTest : public CxxTest::TestSuite {

public:
    void testConstructor() {
        World *world = new World();
        TS_ASSERT_EQUALS(world->getPlayer()->getName(), "Twen");
        TS_ASSERT_EQUALS(world->curMenuOption, 0);
        TS_ASSERT_EQUALS(world->getCurrentGameState(), OVERWORLD);

    }

    void testMovePlayer() {
        World *world = new World();
        TS_ASSERT_EQUALS(world->getPlayer()->getPosition()->getX(), 0);
        TS_ASSERT_EQUALS(world->getPlayer()->getPosition()->getY(), 0);
        world->movePlayer(RIGHT);
        TS_ASSERT_EQUALS(world->getPlayer()->getPosition()->getX(), 1);
        TS_ASSERT_EQUALS(world->getPlayer()->getPosition()->getY(), 0);
    }

    void testAddToInventory() {
        Item *item = new Item("IT", "EM");
        Item *meti = new Item("Back", "Wards");
        World *world = new World();
        world->addToInventory(item);
        TS_ASSERT_EQUALS(world->getInventory()[0]->getName(), "IT");
        world->addToInventory(meti);
        TS_ASSERT_EQUALS(world->getInventory()[1]->getName(), "Back");
    }


};

#endif //CS3520_2017FA_PROJ_WORLDTEST_H
