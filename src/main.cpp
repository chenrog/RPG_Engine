#include <iostream>
#include "SDL2/SDL.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
int main( int argc, char* args[] ) {

    SDL_Window *window;                    // Declare a pointer to the window

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

// Create an application window with the following settings:
    window = SDL_CreateWindow(
            "AR-CUBED RPG",                    // window title
            SDL_WINDOWPOS_UNDEFINED,           // initial x position
            SDL_WINDOWPOS_UNDEFINED,           // initial y position
            SCREEN_WIDTH,                      // width, in pixels
            SCREEN_HEIGHT,                     // height, in pixels
            SDL_WINDOW_OPENGL                  // flags - see below
    );

// Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

// A basic main loop to prevent blocking
    bool is_running = true;
    SDL_Event event;
    while (is_running) {
            /* Poll for events. SDL_PollEvent() returns 0 when there are no  */
            /* more events on the event queue, our while loop will exit when */
            /* that occurs.                                                  */
        while (SDL_PollEvent(&event)) {
            switch(event.type) {
                // quit out of the game
                case SDL_QUIT:
                    is_running = false;

                case SDL_KEYDOWN:
                    printf( "Key press detected\n" );
                break;

                case SDL_KEYUP:
                    printf( "Key release detected\n" );
                break;
            }
        }
        SDL_Delay(16);
    }

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}