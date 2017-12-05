#include <SDL.h>
#include <random>
#include "GameWindow.h"
#include "../model/Battle/Battle.h"

GameWindow::GameWindow(string title, unsigned int width, unsigned int height, unsigned int multiplier) {
    this->title = move(title);
    this->width = width;
    this->height = height;
    this->multiplier = multiplier;
    this->game = new World();
    // this calls init and sets the state of closed based on if the window opens properly
    closed = !init();
}

bool GameWindow::init() {
    // attempt to initialize everything
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cerr << "Failed to initialize SDL2" << endl;
    }
    /**
    if (TTF_Init() = -1) {
        cerr << "Failed to initialize TTF" << endl;
    }
     **/

    // create a window with the following settings
    window = SDL_CreateWindow(
            title.c_str(),                    // window title
            SDL_WINDOWPOS_CENTERED,           // initial x position
            SDL_WINDOWPOS_CENTERED,           // initial y position
            width * multiplier,               // width, in pixels
            height * multiplier,              // height, in pixels
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
    /** TTF_Quit(); **/
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

                // check for specific key press, output based on current game state
            case SDL_KEYDOWN:
                // OVERWORLD
                if (game->getCurrentGameState() == OVERWORLD) {
                    bool moved = false;
                    direction_t direction;
                    switch (event.key.keysym.sym) {
                        // left
                        case SDLK_LEFT: {
                            direction = LEFT;
                            moved = true;
                            break;
                        }
                            // right
                        case SDLK_RIGHT: {
                            direction = RIGHT;
                            moved = true;
                            break;
                        }
                            // up
                        case SDLK_UP: {
                            direction = UP;
                            moved = true;
                            break;
                        }
                            // down
                        case SDLK_DOWN: {
                            direction = DOWN;
                            moved = true;
                            break;
                        }
                            // "P" key: pauses
                        case SDLK_p: {
                            game->setCurrentGameState(MENU);
                            break;
                        }
                        case SDLK_x: {
                            int x = game->getPlayer()->getPosition()->getX();
                            int y = game->getPlayer()->getPosition()->getY();
                            switch (game->getPlayer()->getDirection()) {
                                case UP: {
                                    if (y != 0 && !game->getWorldMap().getWorldMap()[x][y - 1]->isEmpty()) {
                                        cout << game->getWorldMap().getWorldMap()[x][y - 1]->getEntity()->getName()
                                             << endl;
                                    }
                                    break;
                                }
                                case DOWN: {
                                    if (y != game->getWorldMap().WORLDMAP_HEIGHT &&
                                        !game->getWorldMap().getWorldMap()[x][y + 1]->isEmpty())
                                        cout << game->getWorldMap().getWorldMap()[x][y + 1]->getEntity()->getName()
                                             << endl;
                                    break;
                                }
                                case LEFT: {
                                    if (x != 0 && !game->getWorldMap().getWorldMap()[x - 1][y]->isEmpty()) {
                                        cout << game->getWorldMap().getWorldMap()[x - 1][y]->getEntity()->getName()
                                             << endl;
                                    }
                                    break;
                                }
                                case RIGHT: {
                                    if (x != game->getWorldMap().WORLDMAP_WIDTH &&
                                        !game->getWorldMap().getWorldMap()[x + 1][y]->isEmpty()) {
                                        cout << game->getWorldMap().getWorldMap()[x + 1][y]->getEntity()->getName()
                                             << endl;
                                    }
                                    break;
                                }
                                default:
                                    break;
                            }
                            break;
                        }
                            // default/unused key
                        default: {
                            break;
                        }
                    }

                    // checks if it was movement
                    if (moved) {
                        game->movePlayer(direction);
                    }
                }


                // MENU
                if (game->getCurrentGameState() == MENU) {
                    switch (event.key.keysym.sym) {
                        // TODO: left: move menu
                        case SDLK_LEFT: {
                            break;
                        }
                            // TODO: right: move menu
                        case SDLK_RIGHT: {
                            break;
                        }
                            // "P" key: unpauses
                        case SDL_SCANCODE_P: {
                            game->setCurrentGameState(OVERWORLD);
                            break;
                        }
                        default: {
                            break;
                        }
                    }
                }


                // BATTLE
                if (game->getCurrentGameState() == BATTLE) {
                    if (game->getPlayer()->get_health() == 0) {
                        /** game->END(); **/
                    } else if (game->getEnemyUnit()->get_health() == 0) {
                        game->setCurrentGameState(OVERWORLD);
                    }

                    switch (event.key.keysym.sym) {
                        case SDLK_LEFT: {
                            if (game->curMenuOption > 0) {
                                game->curMenuOption--;
                                cout << game->curMenuOption + 1 << ": " << this->menuStrings[game->curMenuOption] << endl;
                            }
                            break;
                        }

                        case SDLK_RIGHT: {
                            if (game->curMenuOption < 3) {
                                game->curMenuOption++;
                                cout << game->curMenuOption + 1 << ": " << this->menuStrings[game->curMenuOption] << endl;
                            }
                            break;
                        }

                        case SDLK_x: {
                            Battle b;
                            PlayerUnit *p = game->getPlayer();
                            EnemyUnit *e = game->getEnemyUnit();

                            if (game->curMenuOption == 0) {
                                b.doBattle(p, e, p->calcBasicAttack());
                            }
                            if (game->curMenuOption == 1) {
                                b.doBattle(p, e, 10);
                            }
                            if (game->curMenuOption == 2) {
                                b.doBattle(p, e, 10);
                            }
                            if (game->curMenuOption == 3) {
                                game->setCurrentGameState(OVERWORLD);
                                cout << "YOU FLED THE BATTLE. weakling..." << endl;
                            }


                            break;
                        }

                        default: {
                            break;
                        }
                    }
                }


                /**
                // enter key
            case SDLK_ENTER:

                // if the player is in the overworld, look for interactions at all adjacencies
                if (game->getCurrentGameState() == 0) {

                    // ********** interactions for beggining battle and collecting item will be made and used here**********


                    // this is the code for making and advancing through text boxes
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

                    break;
                }

                // if the player is in the menu, select option being hovered
                if (game->getCurrentGameState() == 1) {
                    //select in menu
                    break;
                }

                // if the player is in the battle menu, select option being hovered
                if (game->getCurrentGameState() == 2) {
                    //select in menu
                    break;
                }

                // if the player is conversing, advance or end the conversation
                if (game->getCurrentGameState() == 3) {
                    // advance the text/make it go away
                    break;
                }
                **/

            default:
                break;
        }
    }
}


void GameWindow::drawWorld() const {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    switch (game->getCurrentGameState()) {
        case OVERWORLD: {

            SDL_Rect cell = SDL_Rect();
            cell.w = multiplier;
            cell.h = multiplier;
            for (int i = 0; i < game->getWorldMap().WORLDMAP_WIDTH; i++) {
                for (int j = 0; j < game->getWorldMap().WORLDMAP_HEIGHT; j++) {
                    MapCell *curCell = game->getWorldMap().getWorldMap()[i][j];
                    cell.x = i * multiplier;
                    cell.y = j * multiplier;

                    if (curCell->isWalkable() && curCell->isRandomEncounterable()) {
                        SDL_SetRenderDrawColor(renderer, 10, 86, 27, 255);

                    } else if(curCell->isWalkable()){
                        SDL_SetRenderDrawColor(renderer, 94, 184, 92, 255);
                    }
                    else{
                        SDL_SetRenderDrawColor(renderer, 217, 83, 79, 255);
                    }
                    SDL_RenderFillRect(renderer, &cell);
                    if (!curCell->isEmpty()) {
                        cell.w = multiplier;
                        cell.h = multiplier;

                        cell.x = curCell->getPosition()->getX() * multiplier;
                        cell.y = curCell->getPosition()->getY() * multiplier;

                        if (curCell->getEntity()->is_item()) {
                            SDL_SetRenderDrawColor(renderer, 238, 216, 150, 255);

                        } else {
                            SDL_SetRenderDrawColor(renderer, 66, 139, 202, 255);
                        }
                        SDL_RenderFillRect(renderer, &cell);
                    }
                }
            }


            SDL_Rect player = SDL_Rect();
            player.w = multiplier;
            player.h = multiplier;
            player.x = game->getPlayer()->getPosition()->getX() * multiplier;
            player.y = game->getPlayer()->getPosition()->getY() * multiplier;
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &player);

            player.w = multiplier / 4;
            player.h = multiplier / 4;
            switch (game->getPlayer()->getDirection()) {
                case UP: {
                    player.x = game->getPlayer()->getPosition()->getX() * multiplier + 15;
                    player.y = game->getPlayer()->getPosition()->getY() * multiplier;
                    break;
                }
                case DOWN: {
                    player.x = game->getPlayer()->getPosition()->getX() * multiplier + 15;
                    player.y = game->getPlayer()->getPosition()->getY() * multiplier + 30;
                    break;
                }
                case LEFT: {
                    player.x = game->getPlayer()->getPosition()->getX() * multiplier;
                    player.y = game->getPlayer()->getPosition()->getY() * multiplier + 15;
                    break;
                }
                case RIGHT: {
                    player.x = game->getPlayer()->getPosition()->getX() * multiplier + 30;
                    player.y = game->getPlayer()->getPosition()->getY() * multiplier + 15;
                    break;
                }
                default:
                    break;
            }
            SDL_SetRenderDrawColor(renderer, 2, 2, 2, 2);

            SDL_RenderFillRect(renderer, &player);
            break;
        }
        case (BATTLE): {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_Rect cell = SDL_Rect();
//            cell.w = 30;
//            cell.h = 30;
//            cell.x = 0;
//            cell.y = 0;
//            SDL_RenderFillRect(renderer, &cell);
//            cell.w = game->getWorldMap().WORLDMAP_WIDTH * multiplier;
//            cell.h = (game->getWorldMap().WORLDMAP_HEIGHT / 3) * multiplier;
//            cell.x = 0;
//            cell.y = 2 * (game->getWorldMap().WORLDMAP_HEIGHT / 3) * multiplier;
//            SDL_SetRenderDrawColor(renderer, 66, 139, 202, 255);
//            SDL_RenderFillRect(renderer, &cell);
            // draw Menu Options
            // top left box
            cell.w = (game->getWorldMap().WORLDMAP_WIDTH * multiplier)/2;
            cell.h = ((game->getWorldMap().WORLDMAP_HEIGHT / 3) * multiplier)/2;
            cell.x = 0;
            cell.y = ((2 * (game->getWorldMap().WORLDMAP_HEIGHT / 3)) * (double) multiplier/1.3);
            if (game->curMenuOption == 0) {
                SDL_SetRenderDrawColor(renderer, 66, 139, 202, 255);
            } else {
                SDL_SetRenderDrawColor(renderer, 227, 178, 178, 255);
            }
            SDL_RenderFillRect(renderer, &cell);
            // top right box
            cell.w = (game->getWorldMap().WORLDMAP_WIDTH * multiplier)/2;
            cell.h = ((game->getWorldMap().WORLDMAP_HEIGHT / 3) * multiplier)/2;
            cell.x = (game->getWorldMap().WORLDMAP_WIDTH * multiplier)/2;
            cell.y = ((2 * (game->getWorldMap().WORLDMAP_HEIGHT / 3)) * (double) multiplier/1.3);
            if (game->curMenuOption == 1) {
                SDL_SetRenderDrawColor(renderer, 66, 139, 202, 255);
            } else {
                SDL_SetRenderDrawColor(renderer, 227, 178, 178, 255);
            }
            SDL_RenderFillRect(renderer, &cell);
            //bottom left box
            cell.w = (game->getWorldMap().WORLDMAP_WIDTH * multiplier)/2;
            cell.h = ((game->getWorldMap().WORLDMAP_HEIGHT / 3) * multiplier);
            cell.x = 0;
            cell.y = 2 * (game->getWorldMap().WORLDMAP_HEIGHT / 3) * multiplier;
            if (game->curMenuOption == 2) {
                SDL_SetRenderDrawColor(renderer, 66, 139, 202, 255);
            } else {
                SDL_SetRenderDrawColor(renderer, 227, 178, 178, 255);
            }
            //bottom right box
            SDL_RenderFillRect(renderer, &cell);
            cell.w = game->getWorldMap().WORLDMAP_WIDTH * multiplier/2;
            cell.h = (game->getWorldMap().WORLDMAP_HEIGHT / 3) * multiplier;
            cell.x = game->getWorldMap().WORLDMAP_WIDTH * multiplier/2;
            cell.y = 2 * (game->getWorldMap().WORLDMAP_HEIGHT / 3) * multiplier;
            if (game->curMenuOption == 3) {
                SDL_SetRenderDrawColor(renderer, 66, 139, 202, 255);
            } else {
                SDL_SetRenderDrawColor(renderer, 227, 178, 178, 255);
            }
            SDL_RenderFillRect(renderer, &cell);

            // player health bar outline
            cell.x = 0;
            cell.y = 0;
            cell.w = (game->getWorldMap().WORLDMAP_WIDTH / 2) * multiplier;
            cell.h = multiplier;
            // enemy health bar outline
            SDL_SetRenderDrawColor(renderer, 17, 126, 52, 255);
            SDL_RenderFillRect(renderer, &cell);
            cell.x = (game->getWorldMap().WORLDMAP_WIDTH / 2) * multiplier;
            cell.y = 0;
            cell.w = (game->getWorldMap().WORLDMAP_WIDTH / 2) * multiplier;
            cell.h = multiplier;
            SDL_SetRenderDrawColor(renderer, 197, 40, 0, 255);
            SDL_RenderFillRect(renderer, &cell);
            // player health bar
            cell.x = 0;
            cell.y = 0;
            cell.w = (game->getWorldMap().WORLDMAP_WIDTH / 2) * multiplier - 5 * (float) game->getPlayer()->get_health()
                                                                             /
                                                                             (float) game->getPlayer()->get_max_health();
            cell.h = multiplier - 5;
            SDL_SetRenderDrawColor(renderer, 94, 184, 92, 255);
            SDL_RenderFillRect(renderer, &cell);
            //enemy health bar
            cell.x = (game->getWorldMap().WORLDMAP_WIDTH / 2) * multiplier + 5;
            cell.y = 0;
            cell.w = (game->getWorldMap().WORLDMAP_WIDTH / 2) * multiplier -
                     5 * (float) game->getEnemyUnit()->get_health()
                     / (float) game->getEnemyUnit()->get_max_health();
            cell.h = multiplier - 5;
            SDL_SetRenderDrawColor(renderer, 217, 83, 79, 255);
            SDL_RenderFillRect(renderer, &cell);

            break;
        }


//        case (MENU):
//            SDL_Rect textBox;
//            textBox.y = 0;
//            textBox.x = 0;
//            textBox.w = 900;
//            textBox.h = 100;
//            SDL_SetRenderDrawColor(renderer, 249, 249, 249, 255);
//            TTF_Font *font = TTF_OpenFont(font / Final - Fantasy.ttf, 14);
//            if (!font) {
//                std::cerr << "failed to load font" << endl;
//            }
//            string paused = "PAUSED";
//            auto text_surface = TTF_RenderText_Solid(font, paused.c_str(), SDL_Color(0, 0, 0));
//            if (!text_surface) {
//                cerr << "failed to create text surface" << endl;
//            }
//            auto text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
//            if (!text_texture) {
//                cerr << "failed to create text_texture" << endl;
//            }
//            SDL_FreeSurface(text_surface);
//            SDL_RenderCopy(renderer, text_texture, nullptr, textBox);
//
//            textBox.y = 100;
//            textBox.x = 0;
//            textBox.w = 450;
//            textBox.h = 100;
//            TTF_Font *font = TTF_OpenFont(font / Final - Fantasy.ttf, 14);
//            if (!font) {
//                std::cerr << "failed to load font" << endl;
//            }
//            auto text_surface = TTF_RenderText_Solid(font, game->getPlayer()->getName().c_str(), SDL_Color(0, 0, 0));
//            if (!text_surface) {
//                cerr << "failed to create text surface" << endl;
//            }
//            auto text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
//            if (!text_texture) {
//                cerr << "failed to create text_texture" << endl;
//            }
//            SDL_FreeSurface(text_surface);
//            SDL_RenderCopy(renderer, text_texture, nullptr, textBox);
//
//            textBox.y = 100;
//            textBox.x = 450;
//            textBox.w = 450;
//            textBox.h = 100;
//            TTF_Font *font = TTF_OpenFont(font / Final - Fantasy.ttf, 14);
//            if (!font) {
//                std::cerr << "failed to load font" << endl;
//            }
//            string level = to_string(game->getPlayer()->get_lvl());
//            auto text_surface = TTF_RenderText_Solid(font, level.c_str(), SDL_Color(0, 0, 0));
//            if (!text_surface) {
//                cerr << "failed to create text surface" << endl;
//            }
//            auto text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
//            if (!text_texture) {
//                cerr << "failed to create text_texture" << endl;
//            }
//            SDL_FreeSurface(text_surface);
//            SDL_RenderCopy(renderer, text_texture, nullptr, textBox);
        default: {
            break;
        }
    }


    SDL_RenderPresent(renderer);
}


