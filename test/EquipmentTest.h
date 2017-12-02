#ifndef CS3520_2017FA_PROJ_EQUIPMENTTEST_H
#define CS3520_2017FA_PROJ_EQUIPMENTTEST_H

#include "../src/model/Item/Equipment/Equipment.h"
#include <cxxtest/TestSuite.h>

#include <iostream>
#include <cstring>

class EquipmentTest {
public:

    void testEquipmentBuilder() {
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
        TS_ASSERT_EQUALS(equipment->getName(), "Helmet");
        TS_ASSERT_EQUALS(equipment->getPosition().getX(), 0);
        TS_ASSERT_EQUALS(equipment->getPosition().getY(), 1);
        TS_ASSERT(equipment->isVisible());
        TS_ASSERT_EQUALS(equipment->getVit(), 1);
        TS_ASSERT_EQUALS(equipment->getIntel(), 2);
        TS_ASSERT_EQUALS(equipment->getStr(), 3);
        TS_ASSERT_EQUALS(equipment->getSpeed(), 4);
        equipment->level_up();
        TS_ASSERT_EQUALS(equipment->getName(), "Helmet");
        TS_ASSERT(equipment->isVisible());
        TS_ASSERT_EQUALS(equipment->getVit(), 6);
        TS_ASSERT_EQUALS(equipment->getIntel(), 8);
        TS_ASSERT_EQUALS(equipment->getStr(), 10);
        TS_ASSERT_EQUALS(equipment->getSpeed(), 12);


    }
};


#endif //CS3520_2017FA_PROJ_EQUIPMENTTEST_H
