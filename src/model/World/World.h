//
// Created by Andrew Alcala on 11/8/2017.
//

#ifndef CS3520_2017FA_PROJ_WORLD_H
#define CS3520_2017FA_PROJ_WORLD_H

#include "../Units/PlayerUnit.h"
#include "../GameState.h"
#include "WorldMap.h"
#include "../Item/Item.h"
#include <vector>


class World {
public:
    World()  {
        worldMap = WorldMap();
        Posn starting_point = Posn(0, 0);
        vector<Equipment> equipmentList;
        vector<Spell>     spellList;
//    this->inventory;
        //TODO: probably need new here.

//        this->player = PlayerUnit("Twen", starting_point, true, STARTING_VIT, STARTING_INT, STARTING_DEX,
//                                  STARTING_STR, STARTING_LVL, true, equipmentList, spellList, STARTING_MOD_VIT,
//                                  STARTING_MOD_INT, STARTING_MOD_DEX, STARTING_MOD_STR);
        this->gameState = OVERWORLD;

    }

    ~World();

    /**
     * Returns the allies.
     * @return The allies.
     */
    PlayerUnit getPlayer();

    /**
     * Function that moves the player based on key input. If the player moves onto a
     * cell that has random encounters, generate whether or not there is an encounter.
     */
    void movePlayer(direction_t direction, int distance);

    /**
     * Returns the inventory as a map corresponding items to their quantity.
     * @return
     */
    //unordered_map<Item, int> getInventory();

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

    inline bool addToInventory(Item item) {
        if (curInventorySize == INVENTORY_SLOTS) {
            return false;
        } else {
            inventory[curInventorySize] = item;
            curInventorySize++;
        }
    }

    inline void trash(int i) {
        Item trash = inventory[i];
        inventory[i] = inventory[curInventorySize];
        inventory[curInventorySize] = trash;
        curInventorySize--;
    }

    // Constants
    const int INVENTORY_SLOTS = 20;
    const int PARTY_SIZE = 2;

    //TODO: not sure what these numbers are yet. i know they change per player though so it wont be const.
    unsigned const int STARTING_VIT = 1;
    unsigned const int STARTING_INT = 1;
    unsigned const int STARTING_DEX = 1;
    unsigned const int STARTING_STR = 1;
    unsigned const int STARTING_LVL = 1;

    unsigned const int STARTING_MOD_VIT = 1;
    unsigned const int STARTING_MOD_INT = 1;
    unsigned const int STARTING_MOD_DEX = 1;
    unsigned const int STARTING_MOD_STR = 1;

    const double RANDOM_ENCOUNTER_CHANCE = .05;

private:
    // Only doing one player for now.
    PlayerUnit player;
    //unordered_map inventory;
    WorldMap worldMap;
    Item inventory[INVENTORY_SLOTS];
    int curInventorySize = 0;
    game_state_t gameState;
    bool gameOver = false;
};


#endif //CS3520_2017FA_PROJ_WORLD_H
