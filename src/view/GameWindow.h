//
// Created by Roger Chen on 11/30/17.
//

#ifndef CS3520_2017FA_PROJ_WINDOW_H
#define CS3520_2017FA_PROJ_WINDOW_H

#include <SDL_video.h>
#include <SDL_render.h>
#include <iostream>
#include "../model/World/World.h"

using namespace std;
class GameWindow {
public:
    GameWindow(string title, unsigned int width, unsigned int height, unsigned int multiplier);
    ~GameWindow();

    bool init();
    inline bool is_closed() {return closed;};
    void pollEvents();
    void drawWorld() const;
    

private:
    // the game being displayed
    World* game;
    // below are properties of an SDL window
    bool closed = false;
    string title;
    unsigned int width;
    unsigned int height;
    unsigned int multiplier;
    // both of the below variables are initialized by the init function
    SDL_Window * window = nullptr;      // Declare a pointer to the window
    SDL_Renderer * renderer = nullptr;  // Declare a pointer to the renderer
    string menuStrings[4] = {"ATTACK", "SPELLS", "ITEM", "FLEE"};
};


#endif //CS3520_2017FA_PROJ_WINDOW_H
