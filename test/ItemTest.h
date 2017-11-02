#ifndef CS3520_2017FA_PROJ_ITEMTEST_H
#define CS3520_2017FA_PROJ_ITEMTEST_H

#include "../src/model/Item/Item.h"
#include <cxxtest/TestSuite.h>
#include <iostream>

class ItemTest : public CxxTest::TestSuite {
public:

    void testMethods() {
        Item item = Item("Name", "Description");
        TS_ASSERT_EQUALS("Name", item.getName());
        TS_ASSERT_EQUALS("Description", item.getDescription());
    }
};


#endif //CS3520_2017FA_PROJ_ITEMTEST_H
