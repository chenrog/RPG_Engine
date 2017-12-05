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
    World();

    ~World();

    /**
     * Returns the allies.
     * @return The allies.
     */
    PlayerUnit* getPlayer() const;

    /**
     * Function that moves the player based on key input. If the player moves onto a
     * cell that has random encounters, generate whether or not there is an encounter.
     */
    void movePlayer(direction_t direction);

    /**
     * Returns the Overworld and all its cells.
     * @return The game's overworld.
     */
    WorldMap getWorldMap() const;

    /**
     * Returns the current game state.
     * @return OVERWORLD, MENU, or BATTLE.
     */
    game_state_t getCurrentGameState() const;

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

    Item **getInventory();

    inline bool addToInventory(Item* item);

    inline void trash(int i);

    // Constants
    static const int INVENTORY_SLOTS = 20;
    /**
    * Sets the current gamestate to the given one
    */
    void setCurrentGameState(game_state_t gameState);

    EnemyUnit * getEnemyUnit();

    int curMenuOption = 0;
private:
    // Only doing one player for now.
    PlayerUnit *player;
    WorldMap *worldMap;
    EnemyUnit *curEnemy;
    Item** inventory;
    int curInventorySize = 0;
    game_state_t gameState;
    bool gameOver = false;
};


#endif //CS3520_2017FA_PROJ_WORLD_H
