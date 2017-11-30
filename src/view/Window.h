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
    GameWindow(string title, int width, int length, int init_x_pos, int init_y_pos)  {
        window = new SDL_Window(title, width, length, init_x_pos, init_y_pos, SDL_WINDOW_OPENGL);

    }

private:
    SDL_Window * window;
    SDL_Renderer * renderer;
};


#endif //CS3520_2017FA_PROJ_WINDOW_H
