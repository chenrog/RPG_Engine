#include <iostream>
#include "SDL2/SDL.h"
#include "SDL_ttf.h"
#include "view/GameWindow.h"

//Screen dimension constants
const int SCREEN_GRID_MULTIPLIER = 25;
const int SCREEN_WIDTH = 30;
const int SCREEN_HEIGHT = 30;

int main( int argc, char* args[] ) {
    // initialize the game
    GameWindow g = GameWindow(
            "Georginacide",
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SCREEN_GRID_MULTIPLIER);

    // A basic main loop to prevent blocking
    while (!g.is_closed()) {
        g.drawWorld();
        g.pollEvents(); // Poll for events (controls).

        SDL_Delay(20); // waits 20 milliseconds
    }

    return 0;
}