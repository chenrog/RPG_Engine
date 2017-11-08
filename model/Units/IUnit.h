//
// Created by whyar on 11/6/2017.
//

#ifndef CS3520_2017FA_PROJ_UNIT_H
#define CS3520_2017FA_PROJ_UNIT_H

#include "../Equipment/Equipment.h"
#include "../Spell.h"
#include "../Item.h"
#include <string>

class IUnit {
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

    /**
     *
     * @return
     */
    virtual Item calcDrop();

    friend int getX(const IUnit &unit);

    friend int getY(const IUnit &unit);

    void setX(int x);

    void setY(int y);


protected:
    virtual const string name;
    virtual unsigned int curr_health, health, cur_mana, mana, p_defense, m_defense;
    virtual unsigned int vit, intel, speed, str;
    virtual unsigned int lvl, exp;
    virtual int pos_x, pos_y;
    bool is_melee;
    virtual Equipment * equip; // each element in the array pertains to a specific stats
    virtual Spell * spells; // will be displayed in a list when the player selects this option
    virtual Item * drop; // randomly will drop an item in this list after defeat
};

#endif //CS3520_2017FA_PROJ_UNIT_H
