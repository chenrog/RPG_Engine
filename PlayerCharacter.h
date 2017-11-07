#ifndef CS3520_2017FA_PROJ_PLAYERCHARACTER_H
#define CS3520_2017FA_PROJ_PLAYERCHARACTER_H

#include "IUnit.h"
#include "Equipment.h"
#include "Spell.h"

class PlayerCharacter : public IUnit {
public:
    /**
    *
    * @param vit
    * @param intel
    * @param dex
    * @param str
    */
    PlayerCharacter(unsigned int vit, unsigned int intel, unsigned int speed, unsigned int str, double mod_vit,
                    double mod_int, double mod_speed, double mod_str, bool is_melee, string name);

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
                    Equipment equipment[], Spell spell[], double mod_vit, double mod_int,
                    double mod_speed, double mod_str, bool is_melee, unsigned int lvl, string name);

    ~PlayerCharacter();

    int takeDamage(const int damage, int hit_chance, bool is_physical);

    int castSpell(const Spell spell); // to be figured out later

    Equipment Equip(Equipment const equipment);

    bool addEXP(int const exp);

    int basicAttack(bool is_physical);

    Item calcDrop();

    void updateStats();

private:
    double mod_vit, mod_int, mod_speed, mod_str;
};


#endif //CS3520_2017FA_PROJ_PLAYERCHARACTER_H
