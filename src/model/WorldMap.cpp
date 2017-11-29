//
// Created by Andrew Alcala on 11/9/2017.
//

#include "WorldMap.h"


WorldMap::WorldMap() {

    // Generate the map.
    for (int i = 0; i < WORLDMAP_HEIGHT; i++) {
        for (int j = 0; j < WORLDMAP_WIDTH; j++) {
            gridMap[i].push_back(MapCell(Point(i, j), true));
        }
    }

}

std::vector<vector<MapCell>> WorldMap::getWorldMap() {
    return gridMap;
}

WorldMap &WorldMap::operator=(const WorldMap &other) {
    this->gridMap = other.gridMap;
    return *this;
}

// some function that controls how this cell is displayed, will be based on whether or not this Cell is "inhabited"
void draw() {
    //holds the body of the function where SDL will display the graphical representation of the map
}