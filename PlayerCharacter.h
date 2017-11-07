#ifndef CS3520_2017FA_PROJ_PLAYERCHARACTER_H
#define CS3520_2017FA_PROJ_PLAYERCHARACTER_H

#include "IUnit.h"

class PlayerCharacter : public IUnit {
    /**
    *
    * @param vit
    * @param intel
    * @param dex
    * @param str
    */
    PlayerCharacter(unsigned int vit, unsigned int intel, unsigned int speed, unsigned int str);

    /**
    *
    * @param vit
    * @param intel
    * @param dex
    * @param str
    * @param equipment
    * @param spell
    */
    PlayerCharacter(unsigned int vit, unsigned int intel, unsigned int dex, unsigned int str,
                    Equipment equipment[], Spells spell[]);

    void takeDamage(const int damage, bool is_physical);

    int castSpell(const Spell spell); // to be figured out later

    void Equip(Equipment const equipment);

    void addEXP(int const exp);

    int basicAttack(bool is_physical);

    Item calcDrop();

    void updateStats();
};


#endif //CS3520_2017FA_PROJ_PLAYERCHARACTER_H
