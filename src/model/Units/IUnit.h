//
// Created by whyar on 11/6/2017.
//

#ifndef CS3520_2017FA_PROJ_UNIT_H
#define CS3520_2017FA_PROJ_UNIT_H


#ifndef CS3520_2017FA_PROJ_SPELLS_H
#include "../Spells/Spell.h"
#endif //CS3520_2017FA_PROJ_SPELL_H
#include "../Equipment/Equipment.h"
#include "../Item/Item.h"
#include "AEntity.h"
#include "../World/Direction.h"
#include <string>
#include <vector>


class Spell;

class IUnit : public AEntity {
public:
    IUnit();

    IUnit(const IUnit &unit);

    ~IUnit();

    /**
     * Move this Unit in the given direction, x distance away
     * @param direction
     */
    virtual void move(direction_t direction, unsigned int distance);

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

    /**
    * updates the statistics of the unit.
    */
    virtual void updateStats();

    unsigned int get_health() const;
    unsigned int get_max_health() const;
    unsigned int get_mana() const;
    unsigned int get_max_mana() const;
    unsigned int get_p_def() const;
    unsigned int get_m_def() const;
    unsigned int get_vit() const;
    unsigned int get_int() const;
    unsigned int get_dex() const;
    unsigned int get_str() const;

protected:
    unsigned int health, max_health, mana, max_mana, p_defense, m_defense;
    unsigned int st_vit, st_int, st_dex, st_str;
    unsigned int lvl, exp;
    bool is_melee;
    vector<Equipment> equipmentList; // each element in the array pertains to a specific stats
    vector<Spell> spellList; // will be displayed in a list when the player selects this option
};

#endif //CS3520_2017FA_PROJ_UNIT_H