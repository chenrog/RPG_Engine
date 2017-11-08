//
// Created by whyar on 11/6/2017.
//

#ifndef CS3520_2017FA_PROJ_UNIT_H
#define CS3520_2017FA_PROJ_UNIT_H

#include "../Equipment/Equipment.h"
#include "../Spell.h"
#include "../Item.h"
#include "AEntity.h"
#include <string>

class IUnit : public AEntity {
public:
    IUnit();

    IUnit(const IUnit &unit);

    virtual ~IUnit();

    /**
     * Calculates the damage a unit takes based on a damage stat passed in by the class. Returns the amount of damage
     * taken by the unit
     * @param damage
     */
    virtual int takeDamage(int damage, int hit_chance, bool is_physical);

    /**
     *
     * @return the damage statistic dealt by this unit.
     */
    virtual int calcBasicAttack();

protected:
    virtual unsigned int health, max_health, mana, max_mana, p_defense, m_defense;
    virtual unsigned int st_vit, st_intel, st_speed, st_str;
    virtual unsigned int lvl, exp;
    bool is_melee;
    virtual Equipment *equip; // each element in the array pertains to a specific stats
    virtual Spell *spells; // will be displayed in a list when the player selects this option
};

#endif //CS3520_2017FA_PROJ_UNIT_H
