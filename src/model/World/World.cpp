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
    worldMap = WorldMap();
    Posn starting_point = Posn(0, 0);
    vector<Equipment> equipmentList;
    vector<Spell>     spellList;
//    this->inventory;
    //TODO: probably need new here.

        this->player = PlayerUnit("Twen", starting_point, STARTING_VIT, STARTING_INT, STARTING_DEX,
                                  STARTING_STR, STARTING_LVL, true, equipmentList, spellList, STARTING_MOD_VIT,
                                  STARTING_MOD_INT, STARTING_MOD_DEX, STARTING_MOD_STR);
    this->gameState = OVERWORLD;

}

PlayerUnit World::getPlayer() {
    return player;
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

inline bool World::addToInventory(Item item) {
    if (curInventorySize == INVENTORY_SLOTS) {
        return false;
    } else {
        inventory[curInventorySize] = item;
        curInventorySize++;
    }
}

inline void World::trash(int i) {
    Item trash = inventory[i];
    inventory[i] = inventory[curInventorySize];
    inventory[curInventorySize] = trash;
    curInventorySize--;
}

//unordered_map<Item, int> World::getInventory() {
//    return inventory;
//}

void World::movePlayer(direction_t direction, int distance)
{
    // Move the player
    player.move(direction, 1);
    // Check for Random Encounter?
    if(worldMap.getWorldMap().at(player.getPosition().getX()).at(player.getPosition().getY()).isRandomEncounterable()){
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<double> dist(0.0, 10.0);
        int random_number = dist(mt); // Between 0 and 9
        if(random_number > 1){
            // initiate a battle sequence
        }
    }
}

World::~World() {

}
