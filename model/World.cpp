//
// Created by Andrew Alcala on 11/8/2017.
//

#include <vector>
#include "World.h"
World::World() {
    vector<Equipment> equipmentList;
    vector<Spell> spellList;

    p1 = new PlayerUnit("Twen", Point(0,0), true, STARTING_VIT, STARTING_INT, STARTING_DEX,
    STARTING_STR, STARTING_LVL, true, equipmentList, spellList, )
}