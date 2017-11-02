#include <iostream>
#include "SDL2/SDL.h"
#include "model/World/World.h"
#include "view/GameWindow.h"

//Screen dimension constants
const int SCREEN_GRID_MULTIPLIER = 100;
const int SCREEN_WIDTH = 9;
const int SCREEN_HEIGHT = 9;

int main( int argc, char* args[] ) {
    // initialize the game
    GameWindow g = GameWindow(
            "$WAG",
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SCREEN_GRID_MULTIPLIER);


    // A basic main loop to prevent blocking
    while (!g.is_closed()) {
        g.pollEvents(); // Poll for events (controls).

        SDL_Delay(20); // waits 20 milliseconds
    }

    return 0;
}