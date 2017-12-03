#include <SDL.h>
#include "GameWindow.h"

GameWindow::GameWindow(string title, unsigned int width, unsigned int height, unsigned int cell_x,
                       unsigned int cell_y) {
    this->title = move(title);
    this->width = width;
    this->height = height;
    this->cell_x = cell_x;
    this->cell_y = cell_y;
    // this calls init and sets the state of closed based on if the window opens properly
    closed = !init();
}

bool GameWindow::init() {
    // attempt to initialize everything
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cerr << "Failed to initialize SDL2" << endl;
    }
    if (TTF_Init() = -1) {
        cerr << "Failed to initialize TTF" << endl;
    }
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
    TTF_Quit();
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
                printf("Key press detected\n");
                break;

                // check for key release
            case SDL_KEYUP:
                printf("Key release detected\n");
                break;

                // default: do nothing
            default:
                break;
        }
    }
}

void GameWindow::drawWorld() const {
    int R = 255;
    int G = 255;
    int B = 255;
    int opacity = 0;
    SDL_SetRenderDrawColor(renderer, R, G, B, opacity);
    SDL_RenderClear(renderer);

    switch (game.getCurrentGameState()) {
        case (0):
            SDL_Rect cell;
            cell.w = cell_x;
            cell.h = cell_y;
            SDL_SetRenderDrawColor(renderer, 94, 184, 92, 255);
            int a = 0;
            int b = 0;
            for (int i = game.getPlayer().getPosition().getX() - 4; i < game.getPlayer().getPosition().getX() + 4; i++) {
                for (int j = game.getPlayer().getPosition().getY() - 4; j < game.getPlayer().getPosition().getY() + 4; j++) {
                    MapCell curCell = game.getWorldMap().getWorldMap()[i][j];
                    cell.x = a * cell_x;
                    cell.y = b * cell_y;
                    if (curCell.isWalkable()) {
                        SDL_SetRenderDrawColor(renderer, 94, 184, 92, 255);

                    } else {
                        SDL_SetRenderDrawColor(renderer, 217, 83, 79, 255);
                    }
                    SDL_RenderFillRect(renderer, cell);
                    if (!curCell.getEntity().isEmpty()) {
                        cell.w = cell_x - 5;
                        cell.h = cell_y - 5;
                        cell.x = curCell.getPosition().getX();
                        cell.y = curCell.getPosition().getY();
                        if (curCell.getEntity().is_item()) {
                            SDL_SetRenderDrawColor(renderer, 220, 105, 0, 255);
                        } else {
                            SDL_SetRenderDrawColor(renderer, 66, 139, 202, 255);
                        }
                        SDL_RenderFillRect(renderer, cell);
                    }
                    b++;
                }
                a++;
            }
            SDL_Rect player;
            player.w = cell_x - 5;
            player.h = cell_y - 5;
            player.x = game.getPlayer().getPosition().getX();
            player.y = game.getPlayer().getPosition().getY();
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            break;
        case(MENU):


    }


    SDL_RenderPresent(renderer);
}


