#include "GameWindow.h"


GameWindow::GameWindow(World game, string title, int width, int length) {
    this->game = game;
    this->title = title;
    this->width = width;
    this->length = length;

    if (!init()) {
        closed = true;
    }
}

bool GameWindow::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cerr << "Failed to initialize SDL2" << endl;
    }
    window = SDL_CreateWindow(title,
                              SDL_WINDOW_POS_CENTERED,
                              SDL_WINDOW_POS_CENTERED,
                              width,
                              length,
                              SDL_WINDOW_MAXIMIZED);
    if (window == nullptr) {
        cerr << "Window failed to create" << endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr) {
        cerr < "Renderer failed to create" << edl;
    }
    return true;
}

GameWindow::~GameWindow() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void GameWindow::pollEvents() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT;
                closed = true;
                break;
            default:
                break;
        }
    }
}

void GameWindow::drawWorld(int R, int G, int B, int opacity) const {
    SDL_SetRendererDrawColor(renderer, R, G, B, opacity);
    switch(game.getCurrentGameState()) {
        case (0) {
            
        }
    }


    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}


