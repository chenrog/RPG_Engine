//
// Created by whyar on 11/6/2017.
//

#include "MapCell.h"
#include "../Units/EnemyUnit.h"
#include <vector>
#include <iostream>


/**
* Class representing a Map.
*/

class WorldMap {
public:
    WorldMap(int numEnemies);

    MapCell*** getWorldMap();

    EnemyUnit ** getEnemies();

    void setEnemy(EnemyUnit * eu);

    int getCurSize();

    static const int WORLDMAP_WIDTH = 30;
    static const int WORLDMAP_HEIGHT = 30;

private:
    //vector<vector<MapCell*>> * gridMap;
    int curEnemies;
    MapCell*** gridMap;
    EnemyUnit ** enemies;
};



