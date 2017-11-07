//
// Created by whyar on 11/6/2017.
//

#ifndef CS3520_2017FA_PROJ_UNIT_H
#define CS3520_2017FA_PROJ_UNIT_H

class IUnit {
public:
    /**
     * Calculates the damage a unit takes based on a damage stat passed in by the class.
     * @param damage
     */
    void takeDamage(const int damage);

    /**
     * Casts the given spell based upon the spell selected by the user.
     * @param spell
     */
    void castSpell(const Spell spell); // to be figured out later

    /**
     * Equips the chosen equipment to the player character and applies stat changes as necessary.
     * @param equipment
     */
    void Equip(Equipment const equipment);

    /**
     * adds EXP from a battle to the exp of this unit. Then calculates if there is a level up by this unit.
     * @param exp
     */
    void addEXP(int const exp);

    /**
     *
     * @return
     */
    int getDamage(int );
    Item calcDrop();


private:
    int health, mana, p_defense, m_defense, p_damage, m_damage;
    int vit, intel, spe, str;
    int max_exp, exp;
    Equipment * equip; // each element in the array pertains to a specific stats
    Spell * spells; // will be displayed in a list when the player selects this option
    Item * drop; // randomly will drop an item in this list after defeat
};

#endif //CS3520_2017FA_PROJ_UNIT_H
