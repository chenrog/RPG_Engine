#include <SDL.h>
#include "GameWindow.h"

GameWindow::GameWindow(string title, unsigned int width, unsigned int height) {
    this->title = move(title);
    this->width = width;
    this->height = height;
    // this calls init and sets the state of closed based on if the window opens properly
    closed = !init();
}

bool GameWindow::init() {
    // attempt to initialize everything
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cerr << "Failed to initialize SDL2" << endl;
    }

//    Uint32 flags = SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_MAXIMIZED;
    // create a window with the following settings
    window = SDL_CreateWindow(
            title.c_str(),                    // window title
            SDL_WINDOWPOS_CENTERED,           // initial x position
            SDL_WINDOWPOS_CENTERED,           // initial y position
            width,                            // width, in pixels
            height,                           // height, in pixels
            SDL_WINDOW_MAXIMIZED
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return false;
    }

    // create a renderer and throw an error if it fails to initialize
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

    // Check that the renderer was successfully created
    if (renderer == NULL) {
        // In the case that the window could not be made...
        printf("Could not create renderer: %s\n", SDL_GetError());
        return false;
    }

    // return true if everything works
    return true;
}

GameWindow::~GameWindow() {
    // Close and destroy the window and renderer
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    // Clean up
    SDL_Quit();
}

void GameWindow::pollEvents() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            // quit out of the game
            case SDL_QUIT:
                this->closed = true;
                break;

            // check for key press
            case SDL_KEYDOWN:
                printf( "Key press detected\n" );
                break;

            // check for key release
            case SDL_KEYUP:
                printf( "Key release detected\n" );
                break;

            // default: do nothing
            default:
                break;
        }
    }
}

void GameWindow::drawWorld(int R, int G, int B, int opacity) const {
    SDL_SetRenderDrawColor(renderer, R, G, B, opacity);

//    switch(game.getCurrentGameState()) {
//        case (0) {
//
//        }
//    }


    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}


