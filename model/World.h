//
// Created by Andrew Alcala on 11/8/2017.
//

#ifndef CS3520_2017FA_PROJ_WORLD_H
#define CS3520_2017FA_PROJ_WORLD_H


#include <vector>
#include <bits/unordered_map.h>
#include "Units/PlayerUnit.h"
#include "GameState.h"
#include "WorldMap.h"
#include "InventoryEntry.h"

class World {
public:
    World();

    ~World();

    /**
     * Returns the allies.
     * @return The allies.
     */
    vector<PlayerUnit> getAllies();

    /**
     * Returns the inventory as a map corresponding items to their quantity.
     * @return
     */
    unordered_map<Item, int> getInventory();

    /**
     * Returns the Overworld and all its cells.
     * @return The game's overworld.
     */
    WorldMap getWorldMap();

    /**
     * Returns the current game state.
     * @return OVERWORLD, MENU, or BATTLE.
     */
    game_state_t getCurrentGameState();

    /**
     * Returns whether or not the game is over.
     * @return Whether the game is over.
     */
    bool isGameOver();

    /**
     * OnTick function to handle all events in game on every tick. Requires the current tick.
     * @param currTick The current tick.
     */
    void onTick(int currTick);

    // Constants
    const int INVENTORY_SLOTS = 5;
    const int PARTY_SIZE = 2;

    //TODO: not sure what these numbers are yet. i know they change per player though so it wont be const.
    const int STARTING_VIT = 1;
    const int STARTING_INT = 1;
    const int STARTING_DEX = 1;
    const int STARTING_STR = 1;
    const int STARTING_LVL = 1;

    const int STARTING_MOD_VIT = 1;
    const int STARTING_MOD_INT = 1;
    const int STARTING_MOD_DEX = 1;
    const int STARTING_MOD_STR = 1;

private:
    vector<PlayerUnit> allies;
    unordered_map<Item, int> inventory;
    WorldMap worldMap;
    game_state_t gameState;
    bool gameOver = false;
};


#endif //CS3520_2017FA_PROJ_WORLD_H
