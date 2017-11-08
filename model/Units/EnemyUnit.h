#include "IUnit.h"

#ifndef CS3520_2017FA_PROJ_ENEMYUNIT_H
#define CS3520_2017FA_PROJ_ENEMYUNIT_H

class EnemyUnit : public IUnit {
    EnemyUnit(unsigned int vit, unsigned int intel, unsigned int speed, unsigned int str, double mod_vit,
               double mod_int, double mod_speed, double mod_str, bool is_melee, string name);
};


#endif //CS3520_2017FA_PROJ_ENEMYUNIT_H
