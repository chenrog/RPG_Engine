#ifndef CS3520_2017FA_PROJ_TESTNPCUNIT_H
#define CS3520_2017FA_PROJ_TESTNPCUNIT_H
#include "../src/model/Units/NPCUnit.h"
#include <cxxtest/TestSuite.h>

#include <iostream>

using namespace std;

class NPCUnitTest : public CxxTest::TestSuite {
public:
    Item item[3];

    void testConstructor() {
        NPCUnit * npcUnit = new NPCUnit(DIALOGUE, Point(0,0), "A", "HI");
        TS_ASSERT_EQUALS(npcUnit->getDialogue(),  "HI");
        TS_ASSERT_EQUALS(npcUnit->getNPCUnitType(),  DIALOGUE);
    }

    void testVendorConstructor() {
        item[0] = Item("Key Item", "THE LEGNEDARY COW");
        item[1] = Item("Lock Item", "THE SADDENED CLOWN");
        item[2] = Item("Shiny Item", "THE BEAUTEOUS BEARDED LADY");

        NPCUnit * npcUnit = new NPCUnit(VENDOR, Point(0,0), "R^3", "Hello World!", item);
        TS_ASSERT_EQUALS(npcUnit->getDialogue(),  "Hello World!");
        TS_ASSERT_EQUALS(npcUnit->getNPCUnitType(),  VENDOR);
        TS_ASSERT_EQUALS(npcUnit->getItem(0).getDescription(), "THE LEGENDARY COW");
        TS_ASSERT_EQUALS(npcUnit->getItem(1).getDescription(), "THE SADDENED CLOWN");
    }

    void testAddItems() {
        item[0] = Item("Key Item", "THE LEGNEDARY COW");
        item[1] = Item("Lock Item", "THE SADDENED CLOWN");
        item[2] = Item("Shiny Item", "THE BEAUTEOUS BEARDED LADY");

        NPCUnit * npcUnit = new NPCUnit(VENDOR, Point(0,0), "R^3", "Hello World!");
        npcUnit->addItems(item);
        TS_ASSERT_EQUALS(npcUnit->getItem(0).getDescription(), "THE LEGENDARY COW");
        TS_ASSERT_EQUALS(npcUnit->getItem(1).getDescription(), "THE SADDENED CLOWN");

    }
};
#endif //CS3520_2017FA_PROJ_TESTNPCUNIT_H
