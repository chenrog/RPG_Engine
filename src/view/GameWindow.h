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
    GameWindow(World game, string title, int width, int length);
    ~GameWindow();
    bool init();
    inline bool is_closed() {return closed;};
    void pollEvents();
    void drawWorld(int R, int G, int B, int opacity) const;
    

private:
    World game;
    bool closed = false;
    string title;
    int width;
    int length;
    SDL_Window * window = nullptr;
    SDL_Renderer * renderer = nullptr;
};


#endif //CS3520_2017FA_PROJ_WINDOW_H
