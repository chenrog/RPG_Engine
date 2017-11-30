//
// Created by Roger Chen on 11/30/17.
//

#ifndef CS3520_2017FA_PROJ_WINDOW_H
#define CS3520_2017FA_PROJ_WINDOW_H

#include <SDL_video.h>
#include <SDL_render.h>
#include <iostream>

using namespace std;
class GameWindow {
public:
    GameWindow(World game, string title, int width, int length, int init_x_pos, int init_y_pos);


private:
    bool is_closed = false;
    string title;
    int width;
    int length;
    SDL_Window * window = nullptr;
    SDL_Renderer * renderer = nullptr;
};


#endif //CS3520_2017FA_PROJ_WINDOW_H
