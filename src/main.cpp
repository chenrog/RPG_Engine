#include <iostream>
#include "SDL2/SDL.h"
#include "view/GameWindow.h"

//Screen dimension constants
const int SCREEN_GRID_MULTIPLIER = 10;
const int SCREEN_WIDTH = 64;
const int SCREEN_HEIGHT = 48;

// TODO: FIX AND TURN ON WORLD IN GameWindow.h

int main( int argc, char* args[] ) {
    // initialize the game
    GameWindow g = GameWindow(
            "$WAG",
            SCREEN_WIDTH * SCREEN_GRID_MULTIPLIER,
            SCREEN_HEIGHT * SCREEN_GRID_MULTIPLIER);


    // A basic main loop to prevent blocking
    while (!g.is_closed()) {
        /* Poll for events. SDL_PollEvent() returns 0 when there are no  */
        /* more events on the event queue, our while loop will exit when */
        /* that occurs.                                                  */
        g.pollEvents();

        SDL_Delay(20); // waits 20 milliseconds
    }

    return 0;
}