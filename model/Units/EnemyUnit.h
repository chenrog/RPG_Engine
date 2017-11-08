#include "IUnit.h"

#ifndef CS3520_2017FA_PROJ_ENEMYUNIT_H
#define CS3520_2017FA_PROJ_ENEMYUNIT_H

class EnemyUnit : public IUnit {
public:
    EnemyUnit(unsigned int vit, unsigned int intel, unsigned int speed, unsigned int str,
              bool is_melee, string name, Item item[]);

    EnemyUnit(const EnemyUnit &unit);

    /**
     * Calculates what drops when the unit is defeated.
     * @return
     */
    Item calcDrop();
};


#endif //CS3520_2017FA_PROJ_ENEMYUNIT_H
