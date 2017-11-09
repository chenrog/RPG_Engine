//
// Created by whyar on 11/6/2017.
//
#ifndef CS3520_2017FA_PROJ_SPELLS_H
#define CS3520_2017FA_PROJ_SPELLS_H

#include "Units/IUnit.h"

class Spell {
public:
    int getDamage(const IUnit & unit);
    bool getDamageType();
    int getHitChance(const IUnit & unit);
private:
    int base_hit_chance;
};

#endif //CS3520_2017FA_PROJ_SPELLS_H
