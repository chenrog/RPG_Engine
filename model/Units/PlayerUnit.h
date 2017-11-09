#ifndef CS3520_2017FA_PROJ_PLAYERCHARACTER_H
#define CS3520_2017FA_PROJ_PLAYERCHARACTER_H

#include "IUnit.h"
#include "../Equipment/Equipment.h"
#include "../Spell.h"

class PlayerUnit : public IUnit {
public:
    /**
     *
     * @param vit
     * @param intel
     * @param speed
     * @param str
     * @param mod_vit
     * @param mod_int
     * @param mod_speed
     * @param mod_str
     * @param is_melee
     * @param name
     */
    PlayerUnit(unsigned int vit, unsigned int intel, unsigned int speed, unsigned int str, double mod_vit,
                    double mod_int, double mod_speed, double mod_str, bool is_melee, string name);

    /**
     *
     * @param vit
     * @param intel
     * @param dex
     * @param str
     * @param equipment
     * @param spell
     * @param mod_vit
     * @param mod_int
     * @param mod_speed
     * @param mod_str
     * @param is_melee
     * @param lvl
     * @param name
     */
    PlayerUnit(unsigned int vit, unsigned int intel, unsigned int dex, unsigned int str,
                    Equipment equipment[], Spell spell[], double mod_vit, double mod_int,
                    double mod_speed, double mod_str, bool is_melee, unsigned int lvl, string name);

    ~PlayerUnit() override;

    /**
     * Equips the chosen equipment to the player character and applies stat changes as necessary. Returns the old
     * equipment, if there is one.
     * @param equipment
     */
    Equipment Equip(Equipment equipment);

    /**
     * adds EXP from a battle to the exp of this unit. Then calculates if there is a level up by this unit. Returns
     * true if there is a level up.
     * @param exp
     */
    bool addEXP(int exp);

    /**
    * updates the statistics of the unit.
    */
    void updateStats();


private:
    double mod_vit, mod_int, mod_speed, mod_str;
};


#endif //CS3520_2017FA_PROJ_PLAYERCHARACTER_H
