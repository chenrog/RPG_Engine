#ifndef CS3520_2017FA_PROJ_ENEMYUNITTEST_H
#define CS3520_2017FA_PROJ_ENEMYUNITTEST_H

#include "../src/model/Units/EnemyUnit.h"
#include <cxxtest/TestSuite.h>

#include <iostream>

// ../src/model/Units/EnemyUnit.cpp ../src/model/Units/IEntity.cpp ../src/model/Units/AUnit.cpp ../src/model/Item/Item.cpp ../src/model/Spells/Spell.cpp ../src/model/World/Posn.cpp

using namespace std;

class EnemyUnitTest : public CxxTest::TestSuite {
public:
    void testConstructor() {
        EnemyUnit *enemyUnit = new EnemyUnit(1, 2, 3, 4, false, "Georgina", vector<Item>());
        TS_ASSERT_EQUALS(enemyUnit->getName(), "Georgina");
        TS_ASSERT(!enemyUnit->isVisible());
        TS_ASSERT_EQUALS(enemyUnit->get_vit(), 1);
        TS_ASSERT_EQUALS(enemyUnit->get_int(), 2);
        TS_ASSERT_EQUALS(enemyUnit->get_dex(), 3);
        TS_ASSERT_EQUALS(enemyUnit->get_str(), 4);
        TS_ASSERT(!enemyUnit->is_melee());
        TS_ASSERT_EQUALS(enemyUnit->get_max_health(), enemyUnit->get_vit() * 100);
        TS_ASSERT_EQUALS(enemyUnit->get_max_mana(), enemyUnit->get_int() * 100);
        TS_ASSERT_EQUALS(enemyUnit->get_health(), enemyUnit->get_max_health());
        TS_ASSERT_EQUALS(enemyUnit->get_mana(), enemyUnit->get_max_mana());
    }

    void testDrop() {
        std::vector<Item> *vector = new std::vector<Item>();
        vector->push_back(Item("Key Item", "MAD COW"));
        EnemyUnit *enemyUnit = new EnemyUnit(1, 2, 3, 4, false, "Georgina", *vector);
        TS_ASSERT_EQUALS(enemyUnit->calcDrop().getDescription(), "MAD COW");

    }
};


#endif //CS3520_2017FA_PROJ_ENEMYUNITTEST_H
