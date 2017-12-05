#ifndef CS3520_2017FA_PROJ_PLAYERCHARACTER_H
#define CS3520_2017FA_PROJ_PLAYERCHARACTER_H

#include "AUnit.h"
#include "../Item/Equipment/Equipment.h"
#include "../Spells/Spell.h"
#include <vector>

class PlayerUnit : public AUnit {
public:
    PlayerUnit();

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
     * @param mod_dex
     * @param mod_dex
     * @param is_melee
     * @param lvl
     * @param name
     */
    PlayerUnit(string name, Posn* position, unsigned int vit, unsigned int intel, unsigned int dex, unsigned int str,
               unsigned int lvl, bool is_melee,
               vector<Equipment>* equipmentList, Spell** spellList,
               double mod_vit, double mod_int, double mod_dex, double mod_str);

    ~PlayerUnit() override;


    /**
     * Equips the chosen equipment to the player character and applies stat changes as necessary. Returns the old
     * equipment, if there is one.
     * @param equipment
     */
    void equip(Equipment equipment, Item** inventory, int curInventorySize);

    /**
     * adds EXP from a battle to the exp of this unit. Then calculates if there is a level up by this unit. Returns
     * true if there is a level up.
     * @param exp
     */
    bool addEXP(int exp);

    direction_t getDirection();

    void setDirection(direction_t direction);


private:
    double mod_vit, mod_int, mod_dex, mod_str;
    direction_t direction;
};


#endif //CS3520_2017FA_PROJ_PLAYERCHARACTER_H
