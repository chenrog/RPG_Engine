#ifndef CS3520_2017FA_PROJ_PLAYERUNITTEST_H
#define CS3520_2017FA_PROJ_PLAYERUNITTEST_H
#include "../src/model/Units/PlayerUnit.h"
#include <cxxtest/TestSuite.h>

#include <iostream>

using namespace std;

/**
 * PLAYER UNIT and GENERAL AUNIT Testing will be done in this suite.
 */
class PlayerUnitTest : public CxxTest::TestSuite {
public:


    void testConstructor() {
        PlayerUnit * playerUnit2 = new PlayerUnit("Test", Point(20, 10), 1, 2, 3, 4, 0, false, vector<Equipment>(), vector<Spell>(), 0.1, 0.2, 0.3, 0.4);
        TS_ASSERT_EQUALS(playerUnit2->getName(), "Test");
        TS_ASSERT_EQUALS(playerUnit2->getPosition().getX(), 20);
        TS_ASSERT_EQUALS(playerUnit2->getPosition().getY(), 10);
        TS_ASSERT(playerUnit2->isVisible());
        TS_ASSERT_EQUALS(playerUnit2->get_vit(), 1);
        TS_ASSERT_EQUALS(playerUnit2->get_int(), 2);
        TS_ASSERT_EQUALS(playerUnit2->get_dex(), 3);
        TS_ASSERT_EQUALS(playerUnit2->get_str(), 4);
        TS_ASSERT_EQUALS(playerUnit2->get_lvl(), 0);
        TS_ASSERT(!playerUnit2->is_melee());
        TS_ASSERT_EQUALS(playerUnit2->get_max_health(), playerUnit->get_vit() *100);
        TS_ASSERT_EQUALS(playerUnit2->get_max_mana(), playerUnit->get_int() *100);
        TS_ASSERT_EQUALS(playerUnit2->get_health(), playerUnit->get_max_health());
        TS_ASSERT_EQUALS(playerUnit2->get_mana(), playerUnit->get_max_mana());
        delete playerUnit;
    }

    void testTakePhysicalDamage() {
        PlayerUnit * playerUnit
                = new PlayerUnit("Twen", Point(0, 0), true, 10, 9, 8, 7, 1, vector<Equipment>(), vector<Spell>(), 0.5, 0.4, 0.3, 0.2);
        TS_ASSERT_EQUALS(playerUnit->get_health(), playerUnit->get_max_health());
        playerUnit->takeDamage(20, 100, true);
        TS_ASSERT_EQUALS(playerUnit->get_health(), playerUnit->get_max_health() - (100 - playerUnit->get_p_def()));
        delete playerUnit;
    }

    void testTakeMagicDamage() {
        PlayerUnit * playerUnit
                = new PlayerUnit("Twen", Point(0, 0), true, 10, 9, 8, 7, 1, vector<Equipment>(), vector<Spell>(), 0.5, 0.4, 0.3, 0.2);
        TS_ASSERT_EQUALS(playerUnit->get_health(), playerUnit->get_max_health());
        playerUnit->takeDamage(20, 100, false);
        TS_ASSERT_EQUALS(playerUnit->get_health(), playerUnit->get_max_health() - (100 - playerUnit->get_m_def()));
        delete playerUnit;
    }

    void testTakeLethalDamage() {
        PlayerUnit * playerUnit
                = new PlayerUnit("Twen", Point(0, 0), true, 10, 9, 8, 7, 1, vector<Equipment>(), vector<Spell>(), 0.5, 0.4, 0.3, 0.2);
        TS_ASSERT_EQUALS(playerUnit->get_health(), playerUnit->get_max_health());
        playerUnit->takeDamage(1000000, 100, false);
        TS_ASSERT_EQUALS(playerUnit->get_health(), 0);
        delete playerUnit;
    }

    void testAddEXP() {
        PlayerUnit * playerUnit
                = new PlayerUnit("Twen", Point(0, 0), true, 10, 9, 8, 7, 1, vector<Equipment>(), vector<Spell>(), 0.5, 0.4, 0.3, 0.2);
        TS_ASSERT_EQUALS(playerUnit->get_lvl(), 1);
        int old_str = playerUnit->get_str();
        int old_int = playerUnit->get_int();
        int old_vit = playerUnit->get_vit();
        int old_dex = playerUnit->get_dex();
        playerUnit->addEXP(150);
        TS_ASSERT_EQUALS(playerUnit->get_lvl(), 2);
        TS_ASSERT(playerUnit->get_str() >= old_str);
        TS_ASSERT(playerUnit->get_int() >= old_int);
        TS_ASSERT(playerUnit->get_vit() >= old_vit);
        TS_ASSERT(playerUnit->get_dex() >= old_dex);
        delete playerUnit;
    }


    void testEquip() {
        PlayerUnit * playerUnit
                = new PlayerUnit("Twen", Point(0, 0), true, 10, 9, 8, 7, 1, vector<Equipment>(), vector<Spell>(), 0.5, 0.4, 0.3, 0.2);
        TS_ASSERT_EQUALS(playerUnit->get_vit(), 1);
        TS_ASSERT_EQUALS(playerUnit->get_int(), 2);
        TS_ASSERT_EQUALS(playerUnit->get_dex(), 3);
        TS_ASSERT_EQUALS(playerUnit->get_str(), 4);
        Equip_Builder *equip_builder = new Equip_Builder("Helmet", HELMET);
        equip_builder->setPosition(Point(0, 1));
        equip_builder->setVit(1);
        equip_builder->setIntel(2);
        equip_builder->setStr(3);
        equip_builder->setSpeed(4);
        equip_builder->setVit_mod(5);
        equip_builder->setInt_mod(6);
        equip_builder->setStr_mod(7);
        equip_builder->setSpeed_mod(8);
        equip_builder->setVisibility(true);
        Equipment *equipment = equip_builder->build();
        Item test[1];
        playerUnit->equip(*equipment, test, 0);
        TS_ASSERT_EQUALS(playerUnit->get_vit(), 2);
        TS_ASSERT_EQUALS(playerUnit->get_int(), 4);
        TS_ASSERT_EQUALS(playerUnit->get_dex(), 6);
        TS_ASSERT_EQUALS(playerUnit->get_str(), 8);

        delete playerUnit;
    }
};

#endif //CS3520_2017FA_PROJ_PLAYERUNITTEST_H
