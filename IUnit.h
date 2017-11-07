//
// Created by whyar on 11/6/2017.
//

#ifndef CS3520_2017FA_PROJ_UNIT_H
#define CS3520_2017FA_PROJ_UNIT_H

class IUnit {
public:
    IUnit();
    IUnit(const IUnit &unit);
    ~IUnit();

    /**
     * Calculates the damage a unit takes based on a damage stat passed in by the class.
     * @param damage
     */
    virtual void takeDamage(const int damage, bool is_physical);

    /**
     * Casts the given spell based upon the spell selected by the user.
     * @param spell
     * @return the damage of the spell
     */
    virtual int castSpell(const Spell spell); // to be figured out later

    /**
     * Equips the chosen equipment to the player character and applies stat changes as necessary.
     * @param equipment
     */
    virtual void Equip(Equipment const equipment);

    /**
     * adds EXP from a battle to the exp of this unit. Then calculates if there is a level up by this unit.
     * @param exp
     */
    virtual void addEXP(int const exp);

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
    virtual unsigned int health, mana, p_defense, m_defense;
    virtual unsigned int vit, intel, speed, str;
    virtual unsigned int max_exp, exp;
    virtual Equipment * equip; // each element in the array pertains to a specific stats
    virtual Spell * spells; // will be displayed in a list when the player selects this option
    virtual Item * drop; // randomly will drop an item in this list after defeat
};

#endif //CS3520_2017FA_PROJ_UNIT_H
