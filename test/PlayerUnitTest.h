#ifndef CS3520_2017FA_PROJ_PLAYERUNITTEST_H
#define CS3520_2017FA_PROJ_PLAYERUNITTEST_H
#include "../src/model/Units/PlayerUnit.h"
#include <cxxtest/TestSuite.h>

#include <iostream>

// ../src/model/Item/Equipment/Equipment.cpp ../src/model/Units/PlayerUnit.cpp ../src/model/Units/IEntity.cpp ../src/model/Units/AUnit.cpp ../src/model/Item/Item.cpp  ../src/model/Spells/Spell.cpp ../src/model/World/Posn.cpp

using namespace std;

/**
 * PLAYER UNIT and GENERAL AUNIT Testing will be done in this suite.
 *
 */
class PlayerUnitTest : public CxxTest::TestSuite {
public:

    // TODO: Rework tests.
    void testConstructor() {
        PlayerUnit * playerUnit2 = new PlayerUnit("Test", Posn(20, 10), 1, 2, 3, 4, 0, false, vector<Equipment>(), vector<Spell>(), 0.1, 0.2, 0.3, 0.4);
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
        TS_ASSERT_EQUALS(playerUnit2->get_max_health(), playerUnit2->get_vit() *100);
        TS_ASSERT_EQUALS(playerUnit2->get_max_mana(), playerUnit2->get_int() *100);
        TS_ASSERT_EQUALS(playerUnit2->get_health(), playerUnit2->get_max_health());
        TS_ASSERT_EQUALS(playerUnit2->get_mana(), playerUnit2->get_max_mana());
        delete playerUnit2;
    }

    void testTakePhysicalDamage() {
        PlayerUnit * playerUnit
                = new PlayerUnit("Twen", Posn(0, 0), 10, 9, 8, 7, 1, true, vector<Equipment>(), vector<Spell>(), 0.5, 0.4, 0.3, 0.2);
        Spell * spell = new Spell("Punch", 50, 2, 100, 100, HEAL, PHYSICAL);
        TS_ASSERT_EQUALS(playerUnit->get_health(), playerUnit->get_max_health());
        playerUnit->takeDamage(*spell, *playerUnit); // TODO: slicing is NOT ok here
        TS_ASSERT_EQUALS(playerUnit->get_health(), playerUnit->get_max_health() - (100 - playerUnit->get_p_def()));
        delete playerUnit;
        delete spell;
    }

    void testTakeMagicDamage() {
        Spell * spell = new Spell("Punch", 10, 2, 100, 100, DAMAGE,PHYSICAL);
        PlayerUnit * playerUnit
                = new PlayerUnit("Twen", Posn(0, 0), 10, 9, 8, 7, 1,  true, vector<Equipment>(), vector<Spell>(), 0.5, 0.4, 0.3, 0.2);
        TS_ASSERT_EQUALS(playerUnit->get_health(), playerUnit->get_max_health());
        playerUnit->takeDamage(*spell, *playerUnit); // TODO: slicing is NOT ok here
        TS_ASSERT_EQUALS(playerUnit->get_health(), playerUnit->get_max_health() - (100 - playerUnit->get_m_def()));
        delete playerUnit;
    }

    void testTakeLethalDamage() {
        Spell * spell = new Spell("Punch", 10, 2, 100, 100, DAMAGE,PHYSICAL);
        PlayerUnit * playerUnit
                = new PlayerUnit("Twen", Posn(0, 0), 10, 9, 8, 7, 1, true, vector<Equipment>(), vector<Spell>(), 0.5, 0.4, 0.3, 0.2);
        TS_ASSERT_EQUALS(playerUnit->get_health(), playerUnit->get_max_health());
        playerUnit->takeDamage(*spell, *playerUnit); // TODO: slicing is NOT ok here
        TS_ASSERT_EQUALS(playerUnit->get_health(), 0);
        delete playerUnit;
    }

    void testAddEXP() {
        PlayerUnit * playerUnit
                = new PlayerUnit("Twen", Posn(0, 0), 10, 9, 8, 7, 1, true,vector<Equipment>(), vector<Spell>(), 0.5, 0.4, 0.3, 0.2);
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
        Spell * spell = new Spell("Punch", 10, 2, 100, 100, DAMAGE,PHYSICAL);

        PlayerUnit * playerUnit
                = new PlayerUnit("Twen", Posn(0, 0), true, 10, 9, 8, 7, 1, vector<Equipment>(), vector<Spell>(), 0.5, 0.4, 0.3, 0.2);
        TS_ASSERT_EQUALS(playerUnit->get_vit(), 1);
        TS_ASSERT_EQUALS(playerUnit->get_int(), 2);
        TS_ASSERT_EQUALS(playerUnit->get_dex(), 3);
        TS_ASSERT_EQUALS(playerUnit->get_str(), 4);
        Equip_Builder *equip_builder = new Equip_Builder("Helmet", HELMET);
        equip_builder->setPosition(0,1);
        equip_builder->setVit(1);
        equip_builder->setIntel(2);
        equip_builder->setStr(3);
        equip_builder->setDex(4);
        equip_builder->setVit_mod(5);
        equip_builder->setInt_mod(6);
        equip_builder->setStr_mod(7);
        equip_builder->setDex_mod(8);
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
