//
// Created by Andrew Alcala on 11/8/2017.
//

#ifndef CS3520_2017FA_PROJ_WORLD_H
#define CS3520_2017FA_PROJ_WORLD_H


#include "Units/PlayerUnit.h"
#include "GameState.h"

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
     * Returns the Overworld and all its cells.
     * @return The game's overworld.
     */
    OverWorld getOverWorld();

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

    int INVENTORY_SLOTS = 5;

private:
    vector<PlayerUnit> allies;
    OverWorld overWorld;
    game_state_t gameState;
    bool gameOver = false;
};


#endif //CS3520_2017FA_PROJ_WORLD_H
