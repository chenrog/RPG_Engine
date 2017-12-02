

#ifndef CS3520_2017FA_PROJ_SPELLTEST_H
#define CS3520_2017FA_PROJ_SPELLTEST_H

#include "../src/model/Spells/Spell.h"
#include "../src/model/Units/PlayerUnit.h"
#include <cxxtest/TestSuite.h>

#include <iostream>
#include <cstring>

class SpellTest {
public:

    void testSpellBuilder() {
        Spell_Builder * sb = new Spell_Builder("Dabonem", DAMAGE, PHYSICAL);
        AUnit * playerUnit
                = new PlayerUnit("Twen", Point(0, 0), true, 10, 9, 8, 7, 1, vector<Equipment>(), vector<Spell>(), 0.5, 0.4, 0.3, 0.2);
        sb->setDamage(10);
        sb->setDamageMod(5);
        sb->setHitChance(100);
        sb->setHitChanceMod(10);
        Spell * spell = sb->build();
        TS_ASSERT_EQUALS(spell->getDamage(*playerUnit), 10 + 5 * 8);
        TS_ASSERT_EQUALS(spell->getDamageType(), PHYSICAL);
        TS_ASSERT_EQUALS(spell->getHitChance(*playerUnit), 100 + 10 * 7);
        TS_ASSERT_EQUALS(spell->getSpellType(), DAMAGE);
    }
};


#endif //CS3520_2017FA_PROJ_SPELLTEST_H
