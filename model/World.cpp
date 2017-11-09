//
// Created by Andrew Alcala on 11/8/2017.
//

#include <vector>
#include "World.h"

/**
 * World Creation method.
 */
World::World() {
    this->worldMap = WorldMap();
    Point starting_point = Point(0, 0);
    vector<Equipment> equipmentList;
    vector<Spell> spellList;
    for (int i = 0; i < PARTY_SIZE; i++) {
        //TODO: probably need new here.
        player = PlayerUnit("Twen", starting_point, true, STARTING_VIT, STARTING_INT, STARTING_DEX,
                            STARTING_STR, STARTING_LVL, true, equipmentList, spellList, STARTING_MOD_VIT,
                            STARTING_MOD_INT, STARTING_MOD_DEX, STARTING_MOD_STR);
        allies.push_back(player);
    }

    this->gameState = OVERWORLD;

}

vector<PlayerUnit> World::getAllies() {
    return allies;
}

WorldMap World::getWorldMap() {
    return worldMap;
}

game_state_t World::getCurrentGameState() {
    return gameState;
}

bool World::isGameOver() {
    return gameOver;
}

void World::onTick(int currTick) {

}

unordered_map<Item, int> World::getInventory() {
    return inventory;
}
