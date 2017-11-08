//
// Created by whyar on 11/6/2017.
//

#ifndef CS3520_2017FA_PROJ_UNIT_H
#define CS3520_2017FA_PROJ_UNIT_H

#include "Equipment.h"
#include "Spell.h"
#include "Item.h"
#include <string>

class IUnit {
public:
    IUnit();
    IUnit(const IUnit &unit);
    ~IUnit();

    /**
     * Calculates the damage a unit takes based on a damage stat passed in by the class. Returns the amount of damage
     * taken by the unit
     * @param damage
     */
    virtual int takeDamage(const int damage, int hit_chance, bool is_physical);

    /**
     * Casts the given spell based upon the spell selected by the user.
     * @param spell
     * @return the damage of the spell
     */
    virtual int castSpell(const Spell spell); // to be figured out later

    /**
     * Equips the chosen equipment to the player character and applies stat changes as necessary. Returns the old
     * equipment, if there is one.
     * @param equipment
     */
    virtual Equipment Equip(Equipment const equipment);

    /**
     * adds EXP from a battle to the exp of this unit. Then calculates if there is a level up by this unit. Returns
     * true if there is a level up.
     * @param exp
     */
    virtual bool addEXP(int const exp);

    /**
     *
     * @return the damage statistic dealt by this unit.
     */
    virtual int basicAttack(bool is_physical);

    /**
     *
     * @return
     */
    virtual Item calcDrop();

    virtual void updateStats();


protected:
    virtual const string name;
    virtual unsigned int curr_health, health, cur_mana, mana, p_defense, m_defense;
    virtual unsigned int vit, intel, speed, str;
    virtual unsigned int lvl, exp;
    bool is_melee;
    virtual Equipment * equip; // each element in the array pertains to a specific stats
    virtual Spell * spells; // will be displayed in a list when the player selects this option
    virtual Item * drop; // randomly will drop an item in this list after defeat
};

#endif //CS3520_2017FA_PROJ_UNIT_H
