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
    WorldMap();

    WorldMap& operator=(const WorldMap& other);

    vector<vector<MapCell>> getWorldMap();

    vector<EnemyUnit> * getEnemies();

    const int WORLDMAP_WIDTH = 30;
    const int WORLDMAP_HEIGHT = 30;

private:
    vector<vector<MapCell>> gridMap;
    vector<EnemyUnit> * enemies;
};



