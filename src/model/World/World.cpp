//
// Created by Andrew Alcala on 11/8/2017.
//

#include "World.h"
#include <ctime>
#include <random>

/**
 * World Creation method.
 */
World::World()  {
    worldMap = new WorldMap();
    Posn starting_point = Posn(0, 0);
    vector<Equipment> equipmentList;
    vector<Spell>     spellList;
//    this->inventory;
    //TODO: probably need new here.
    this->player = new PlayerUnit("Twen", starting_point, STARTING_VIT, STARTING_INT, STARTING_DEX,
                                  STARTING_STR, STARTING_LVL, true, equipmentList, spellList, STARTING_MOD_VIT,
                                  STARTING_MOD_INT, STARTING_MOD_DEX, STARTING_MOD_STR);
    this->gameState = OVERWORLD;

}

PlayerUnit World::getPlayer() const {
    return *player;
}

WorldMap World::getWorldMap() const {
    return *worldMap;
}

game_state_t World::getCurrentGameState() const {
    return gameState;
}

bool World::isGameOver() {
    return gameOver;
}

void World::onTick(int currTick) {

}

inline bool World::addToInventory(Item item) {
    if (curInventorySize == INVENTORY_SLOTS) {
        return false;
    } else {
        inventory[curInventorySize] = item;
        curInventorySize++;
        return true;
    }
}

inline void World::trash(int i) {
    Item trash = inventory[i];
    inventory[i] = inventory[curInventorySize];
    inventory[curInventorySize] = trash;
    curInventorySize--;
}

void World::movePlayer(direction_t direction, int distance) {
    // Move the player
    player->move(direction, 1);

    // Check for Random Encounter?
    vector<vector<MapCell>> map = worldMap->getWorldMap();
    auto x = player->getPosition().getX();
    auto y = player->getPosition().getY();
    if(map[x][y].isRandomEncounterable()){
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<double> dist(0.0, 10.0);
        int random_number = dist(mt); // Between 0 and 9
        if (random_number > 1) {
            // initiate a battle sequence
        }
    }
}

void World::setCurrentGameState(game_state_t newGameState) {
    this->gameState = newGameState;
}

World::~World() {

}
