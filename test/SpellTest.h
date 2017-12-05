

#ifndef CS3520_2017FA_PROJ_SPELLTEST_H
#define CS3520_2017FA_PROJ_SPELLTEST_H

#include "../src/model/Spells/Spell.h"
#include "../src/model/Units/PlayerUnit.h"
#include <cxxtest/TestSuite.h>

#include <iostream>

// Linker files: ../src/model/Units/IEntity.cpp ../src/model/Units/AUnit.cpp ../src/model/Units/PlayerUnit.cpp ../src/model/Item/Item.cpp ../src/model/Spells/Spell.cpp ../src/model/World/Posn.cpp ../src/model/Item/Equipment/Equipment.cpp

class SpellTest : public CxxTest::TestSuite {
public:

    void testSpellBuilder() {
        Spell_Builder * sb = new Spell_Builder("Dabonem", DAMAGE, PHYSICAL);
        AUnit * playerUnit
                = new PlayerUnit("Twen", new Posn(0, 0), 10, 9, 8, 7, 1, true,new  vector<Equipment>(), nullptr, 0.5, 0.4, 0.3, 0.2);
        sb->setDamage(10);
        sb->setDamageMod(5);
        sb->setHitChance(100);
        sb->setHitChanceMod(10);
        Spell * spell = sb->build();
        TS_ASSERT_EQUALS(spell->getDamage(playerUnit), 10 + 5 * 7);
        TS_ASSERT_EQUALS(spell->getDamageType(), PHYSICAL);
        TS_ASSERT_EQUALS(spell->getHitChance(playerUnit), 100 + 10 * 8);
        TS_ASSERT_EQUALS(spell->getSpellType(), DAMAGE);
    }
};


#endif //CS3520_2017FA_PROJ_SPELLTEST_H
