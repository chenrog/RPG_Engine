#ifndef CS3520_2017FA_PROJ_ITEMTEST_H
#define CS3520_2017FA_PROJ_ITEMTEST_H

#include "../src/model/Item/Item.h"
#include <cxxtest/TestSuite.h>
#include <iostream>

// Linker files: ../src/model/Item/Item.cpp ../src/model/Units/IEntity.cpp ../src/model/World/Posn.cpp

class ItemTest : public CxxTest::TestSuite {
public:

    void testMethods() {
        Item item = Item("Name", "Description");
        TS_ASSERT_EQUALS("Name", item.getName());
        TS_ASSERT_EQUALS("Description", item.getDescription());
    }
};


#endif //CS3520_2017FA_PROJ_ITEMTEST_H
