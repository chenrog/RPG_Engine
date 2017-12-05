#ifndef CS3520_2017FA_PROJ_BATTLEMODE_H
#define CS3520_2017FA_PROJ_BATTLEMODE_H

#include "../Units/EnemyUnit.h"
#include "../Units/PlayerUnit.h"

class Battle {
public:
    static void doBattle(PlayerUnit* player, EnemyUnit* enemy, unsigned int attack);
};

#endif //CS3520_2017FA_PROJ_BATTLEMODE_H
