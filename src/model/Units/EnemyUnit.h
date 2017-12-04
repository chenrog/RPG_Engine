#ifndef CS3520_2017FA_PROJ_ENEMYUNIT_H
#define CS3520_2017FA_PROJ_ENEMYUNIT_H

#include "AUnit.h"
#include "../Item/Item.h"
#include <tuple>

class EnemyUnit : public AUnit {
public:
    EnemyUnit();

    EnemyUnit(unsigned int vit, unsigned int intel, unsigned int speed, unsigned int str,
              bool is_melee, string name, vector<Item> drop);

    EnemyUnit(Posn posn, unsigned int vit, unsigned int intel, unsigned int speed, unsigned int str,
              bool is_melee, string name, vector<Item> drop);

    EnemyUnit(const EnemyUnit &unit);

    /**
     * Calculates what drops when the unit is defeated.
     * @return the item determined randomly
     */
    Item calcDrop();

private:
    vector<Item> drop; // randomly will drop an item in this list after defeat
};


#endif //CS3520_2017FA_PROJ_ENEMYUNIT_H
