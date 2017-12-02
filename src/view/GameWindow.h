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
    GameWindow(string title, unsigned int width, unsigned int height);
    ~GameWindow();

    bool init();
    inline bool is_closed() {return closed;};
    void pollEvents();
    void drawWorld(int R, int G, int B, int opacity) const;
    

private:
    // the game being displayed
    // TODO: Fix world
    World game = World();
    // below are properties of an SDL window
    bool closed = false;
    string title;
    unsigned int width;
    unsigned int height;
    // both of the below variables are initialized by the init function
    SDL_Window * window = nullptr;      // Declare a pointer to the window
    SDL_Renderer * renderer = nullptr;  // Declare a pointer to the renderer
};


#endif //CS3520_2017FA_PROJ_WINDOW_H
