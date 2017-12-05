#ifndef CS3520_2017FA_PROJ_TESTNPCUNIT_H
#define CS3520_2017FA_PROJ_TESTNPCUNIT_H
#include "../src/model/Units/NPCUnit.h"
#include <cxxtest/TestSuite.h>

#include <iostream>

// ../src/model/Units/NPCUnit.cpp ../src/model/Units/IEntity.cpp ../src/model/Units/AUnit.cpp ../src/model/Item/Item.cpp ../src/model/Spells/Spell.cpp ../src/model/World/Posn.cpp

using namespace std;

class NPCUnitTest : public CxxTest::TestSuite {
public:

    void testConstructor() {
        NPCUnit * npcUnit = new NPCUnit(DIALOGUE, new Posn(0,0), "A", "HI");
        TS_ASSERT_EQUALS(npcUnit->getDialogue(),  "HI");
        TS_ASSERT_EQUALS(npcUnit->getNPCUnitType(),  DIALOGUE);
    }

    void testVendorConstructor() {
        Item** item = new Item*[3];
        item[0] = new Item("Key Item", "THE LEGENDARY COW");
        item[1] = new Item("Lock Item", "THE SADDENED CLOWN");
        item[2] = new Item("Shiny Item", "THE BEAUTEOUS BEARDED LADY");

        NPCUnit * npcUnit = new NPCUnit(VENDOR, new Posn(0,0), "R^3", "Hello World!", item);
        TS_ASSERT_EQUALS(npcUnit->getDialogue(),  "Hello World!");
        TS_ASSERT_EQUALS(npcUnit->getNPCUnitType(),  VENDOR);
        TS_ASSERT_EQUALS(npcUnit->getItem(0)->getDescription(), "THE LEGENDARY COW");
        TS_ASSERT_EQUALS(npcUnit->getItem(1)->getDescription(), "THE SADDENED CLOWN");
        delete [] item;
    }

    void testAddItems() {
        Item** item = new Item*[3];
        item[0] = new Item("Key Item", "THE LEGENDARY COW");
        item[1] = new Item("Lock Item", "THE SADDENED CLOWN");
        item[2] = new Item("Shiny Item", "THE BEAUTEOUS BEARDED LADY");

        NPCUnit * npcUnit = new NPCUnit(VENDOR, new Posn(0,0), "R^3", "Hello World!");
        npcUnit->setItems(item);
        TS_ASSERT_EQUALS(npcUnit->getItem(0)->getDescription(), "THE LEGENDARY COW");
        TS_ASSERT_EQUALS(npcUnit->getItem(1)->getDescription(), "THE SADDENED CLOWN");
    }
};
#endif //CS3520_2017FA_PROJ_TESTNPCUNIT_H
