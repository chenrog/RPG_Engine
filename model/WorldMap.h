//
// Created by whyar on 11/6/2017.
//

#include <iostream>
#include <vector>
#include "MapCell.h"

/**
* Class representing a Map.
*/

class WorldMap {
public:
    WorldMap();

    vector<vector<MapCell>> getWorldMap();

    const int WORLDMAP_WIDTH = 30;
    const int WORLDMAP_HEIGHT = 30;

private:
    vector<vector<MapCell>> map;
};



