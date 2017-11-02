#include <SDL.h>
#include "GameWindow.h"

GameWindow::GameWindow(string title, unsigned int width, unsigned int height, unsigned int multiplier) {
    this->title = move(title);
    this->width = width;
    this->height = height;
    this->multiplier = multiplier;
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

                // check for specific key press, output based on current game state
                switch (event.key.keysym.sym) {

                    // left arrow key
                    case SDLK_LEFT:

                        // if the player is in the overworld, move left
                        if (game.getCurrentGameState == 0) {
                            game.getPlayer.movePlayer(LEFT, 1);
                            break;
                        }

                        // if the player is in the menu, navigate left
                        if (game.getCurrentGameState == 1) {
                            // move to the left-er option in the general menu, unless it hits a bound
                            break;
                        }

                        // if the player is in the battle menu, navigate left
                        if (game.getCurrentGameState == 2) {
                            // move to the left-er option in the battle menu, unless it hits a bound
                            break;
                        }

                        // if the player is conversing, advance or end the conversation
                        if (game.getCurrentGameState == 3) {
                            // advance the text/make it go away
                            break;
                        }

                        // right arrow key
                    case SDLK_RIGHT:

                        // if the player is in the overworld, move right
                        if (game.getCurrentGameState == 0) {
                            game.getPlayer.movePlayer(RIGHT, 1);
                            break;
                        }

                        // if the player is in the menu, navigate right
                        if (game.getCurrentGameState == 1) {
                            // move to the right-er option in the general menu, unless it hits a bound
                            break;
                        }

                        // if the player is in the battle menu, navigate right
                        if (game.getCurrentGameState == 2) {
                            // move to the right-er option in the battle menu, unless it hits a bound
                            break;
                        }

                        // if the player is conversing, advance or end the conversation
                        if (game.getCurrentGameState == 3) {
                            // advance the text/make it go away
                            break;
                        }

                        // up arrow key
                    case SDLK_UP:

                        // if the player is in the overworld, move up
                        if (game.getCurrentGameState == 0) {
                            game.getPlayer.movePlayer(UP, 1);
                            break;
                        }

                        // if the player is in the menu, do nothing
                        if (game.getCurrentGameState == 1) {
                            break;
                        }

                        // if the player is in the battle menu, do nothing
                        if (game.getCurrentGameState == 2) {
                            break;
                        }

                        // if the player is conversing, advance or end the conversation
                        if (game.getCurrentGameState == 3) {
                            // advance the text/make it go away
                            break;
                        }

                        // down arrow key
                    case SDLK_DOWN:

                        // if the player is in the overworld, move down
                        if (game.getCurrentGameState == 0) {
                            game.getPlayer.movePlayer(DOWN, 1);
                            break;
                        }

                        // if the player is in the menu, do nothing
                        if (game.getCurrentGameState == 1) {
                            break;
                        }

                        // if the player is in the battle menu, do nothing
                        if (game.getCurrentGameState == 2) {
                            break;
                        }

                        // if the player is conversing, advance or end the conversation
                        if (game.getCurrentGameState == 3) {
                            // advance the text/make it go away
                            break;
                        }


                        // enter key
                    case SDLK_ENTER:

                        // if the player is in the overworld, look for interactions at all adjacencies
                        if (game.getCurrentGameState == 0) {

                            // ********** interactions for beggining battle and collecting item will be made and used here**********


                            // this is the code for making and advancing through text boxes
                            /*
                            SDL_Rect textBox;
                            textBox.y = 600;
                            textBox.x = 0;
                            textBox.w = 900;
                            textBox.h = 300;
                            SDL_SetRenderDrawColor(renderer, 249, 249, 249, 255);
                            TTF_Font * font = TTF_OpenFont(font / Final - Fantasy.ttf, 14);
                            if (!font) {
                            std::cerr << "failed to load font" << endl;
                            }
                            auto text_surface = TTF_RenderText_Solid(font, message.c_str(), SDL_Color(0, 0, 0));
                            if (!text_surface) {
                            cerr << "failed to create text surface" << endl;
                            }
                            auto text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
                            if (!text_texture) {
                            cerr << "failed to create text_texture" << endl;
                            }
                            SDL_FreeSurface(text_surface);
                            SDL_RenderCopy(renderer, text_texture, nullptr, textBox);
                            */
                            break;
                        }

                        // if the player is in the menu, select option being hovered
                        if (game.getCurrentGameState == 1) {
                            //select in menu
                            break;
                        }

                        // if the player is in the battle menu, select option being hovered
                        if (game.getCurrentGameState == 2) {
                            //select in menu
                            break;
                        }

                        // if the player is conversing, advance or end the conversation
                        if (game.getCurrentGameState == 3) {
                            // advance the text/make it go away
                            break;
                        }

                        // "P" key
                    case SDLK_P:

                        // if the player is in the overworld, goes to menu game state
                        if (game.getCurrentGameState == 0) {
                            game.setCurrentGameState(MENU);
                            break;
                        }

                        // if the player is in the menu, goes to overworld game state
                        if (game.getCurrentGameState == 1) {
                            game.setCurrentGameState(OVERWORLD);
                            break;
                        }

                        // if the player is in the battle menu, do nothing
                        if (game.getCurrentGameState == 2) {
                            break;
                        }

                        // if the player is conversing, do nothing
                        if (game.getCurrentGameState == 3) {
                            break;
                        }


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
            for (int i = game.getPlayer().getPosition().getX() - 4;
                 i < game.getPlayer().getPosition().getX() + 4; i++) {
                for (int j = game.getPlayer().getPosition().getY() - 4;
                     j < game.getPlayer().getPosition().getY() + 4; j++) {
                    MapCell curCell = game.getWorldMap().getWorldMap()[i][j];
                    cell.x = a * cell_x;
                    cell.y = b * cell_y;
                    if (curCell.isWalkable()) {
                        SDL_SetRenderDrawColor(renderer, 94, 184, 92, 255);

                    } else {
                        SDL_SetRenderDrawColor(renderer, 217, 83, 79, 255);
                    }
                    SDL_RenderFillRect(renderer, cell);
                    if (!curCell.isEmpty()) {
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
        case (MENU):
            SDL_Rect textBox;
            textBox.y = 0;
            textBox.x = 0;
            textBox.w = 900;
            textBox.h = 100;
            SDL_SetRenderDrawColor(renderer, 249, 249, 249, 255);
            TTF_Font *font = TTF_OpenFont(font / Final - Fantasy.ttf, 14);
            if (!font) {
                std::cerr << "failed to load font" << endl;
            }
            string paused = "PAUSED";
            auto text_surface = TTF_RenderText_Solid(font, paused.c_str(), SDL_Color(0, 0, 0));
            if (!text_surface) {
                cerr << "failed to create text surface" << endl;
            }
            auto text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
            if (!text_texture) {
                cerr << "failed to create text_texture" << endl;
            }
            SDL_FreeSurface(text_surface);
            SDL_RenderCopy(renderer, text_texture, nullptr, textBox);

            textBox.y = 100;
            textBox.x = 0;
            textBox.w = 450;
            textBox.h = 100;
            TTF_Font *font = TTF_OpenFont(font / Final - Fantasy.ttf, 14);
            if (!font) {
                std::cerr << "failed to load font" << endl;
            }
            auto text_surface = TTF_RenderText_Solid(font, game.getPlayer().getName().c_str(), SDL_Color(0, 0, 0));
            if (!text_surface) {
                cerr << "failed to create text surface" << endl;
            }
            auto text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
            if (!text_texture) {
                cerr << "failed to create text_texture" << endl;
            }
            SDL_FreeSurface(text_surface);
            SDL_RenderCopy(renderer, text_texture, nullptr, textBox);

            textBox.y = 100;
            textBox.x = 450;
            textBox.w = 450;
            textBox.h = 100;
            TTF_Font *font = TTF_OpenFont(font / Final - Fantasy.ttf, 14);
            if (!font) {
                std::cerr << "failed to load font" << endl;
            }
            string level = to_string(game.getPlayer().get_lvl());
            auto text_surface = TTF_RenderText_Solid(font, level.c_str(), SDL_Color(0, 0, 0));
            if (!text_surface) {
                cerr << "failed to create text surface" << endl;
            }
            auto text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
            if (!text_texture) {
                cerr << "failed to create text_texture" << endl;
            }
            SDL_FreeSurface(text_surface);
            SDL_RenderCopy(renderer, text_texture, nullptr, textBox);


    }


    SDL_RenderPresent(renderer);
}


