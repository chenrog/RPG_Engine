//
// Created by Andrew Alcala on 11/9/2017.
//

#include "WorldMap.h"


WorldMap::WorldMap(int numEnemies) {
    gridMap = new MapCell**[WORLDMAP_WIDTH];
    for (int i = 0; i < WORLDMAP_WIDTH; i++) {
        gridMap[i] = new MapCell*[WORLDMAP_HEIGHT];
    }
    // Generate the map.
    for (int i = 0; i < WORLDMAP_HEIGHT; i++) {
        for (int j = 0; j < WORLDMAP_WIDTH; j++) {
            gridMap[i][j] = new MapCell(new Posn(i, j), true);;
        }
    }
    curEnemies = 0;
    this->enemies = new EnemyUnit*[numEnemies];

}

EnemyUnit ** WorldMap::getEnemies() {
    return this->enemies;
}

MapCell***  WorldMap::getWorldMap() {
    return gridMap;
}

void WorldMap::setEnemy(EnemyUnit *eu) {
    this->enemies[curEnemies] = eu;
    curEnemies++;
}

int WorldMap::getCurSize() {
    return this->curEnemies;
}

//WorldMap &WorldMap::operator=(const WorldMap &other) {
//    this->gridMap = other.gridMap;
//    return *this;
//}

// some function that controls how this cell is displayed, will be based on whether or not this Cell is "inhabited"
void draw() {
    //holds the body of the function where SDL will display the graphical representation of the map
}