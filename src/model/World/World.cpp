//
// Created by Andrew Alcala on 11/8/2017.
//

#include "World.h"
#include "../Units/NPCUnit.h"
#include <random>

/**
 * World Creation method.
 */
World::World()  {
    worldMap = new WorldMap(1);
    NPCUnit * npcUnit = new NPCUnit(DIALOGUE, new Posn(0,0), "A", "HI");
    Item * item = new Item("Name", "Description");
    EnemyUnit *enemyUnit = new EnemyUnit(1, 2, 3, 4, false, "Georgina", new vector<Item>());
    worldMap->setEnemy(enemyUnit);
    worldMap->getWorldMap()[0][7]->setEntity(npcUnit);
    worldMap->getWorldMap()[5][5]->setEntity(item);
    worldMap->getWorldMap()[10][10]->setWalkability(false);
    for (int i = 15; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            worldMap->getWorldMap()[i][j]->setRandomEncounters(true);
        }
    }
    Posn * starting_point = new Posn(0, 0);
    vector<Equipment>* equipmentList;
    vector<Spell>*     spellList;
//    this->inventory;
    //TODO: probably need new here.
    this->player = new PlayerUnit("Twen", starting_point, STARTING_VIT, STARTING_INT, STARTING_DEX,
                                  STARTING_STR, STARTING_LVL, true, equipmentList, spellList, STARTING_MOD_VIT,
                                  STARTING_MOD_INT, STARTING_MOD_DEX, STARTING_MOD_STR);
    this->gameState = OVERWORLD;
    this->curEnemy = new EnemyUnit();

}

PlayerUnit* World::getPlayer() const {
    return player;
}

WorldMap World::getWorldMap() const {
    return *worldMap;
}

game_state_t World::getCurrentGameState() const {
    return gameState;
}

bool World::isGameOver() {
    return gameOver;
}

void World::onTick(int currTick) {

}

inline bool World::addToInventory(Item item) {
    if (curInventorySize == INVENTORY_SLOTS) {
        return false;
    } else {
        inventory[curInventorySize] = std::move(item);
        curInventorySize++;
        return true;
    }
}

inline void World::trash(int i) {
    Item trash = inventory[i];
    inventory[i] = inventory[curInventorySize];
    inventory[curInventorySize] = trash;
    curInventorySize--;
}

void World::movePlayer(direction_t direction) {
    switch (direction) {
        case UP:
            if (this->player->getPosition()->getY() != 0 &&
                    this->worldMap->getWorldMap()[this->player->getPosition()->getX()]
                    [this->player->getPosition()->getY() - 1]->isWalkable()) {
                this->player->getPosition()->setY(this->player->getPosition()->getY() - 1);
            }
            break;
        case DOWN:
            if (this->player->getPosition()->getY() != worldMap->WORLDMAP_HEIGHT &&
                this->worldMap->getWorldMap()[this->player->getPosition()->getX()]
                [this->player->getPosition()->getY() + 1]->isWalkable()) {
                this->player->getPosition()->setY((this->player->getPosition()->getY() + 1));
            }
            break;
        case LEFT:
            if (this->player->getPosition()->getX() != 0 &&
                this->worldMap->getWorldMap()[this->player->getPosition()->getX() -1]
                [this->player->getPosition()->getY()]->isWalkable()) {
                this->player->getPosition()->setX((this->player->getPosition()->getX() - 1));
            }
            break;
        case RIGHT:
            if (this->player->getPosition()->getX() != worldMap->WORLDMAP_WIDTH &&
                this->worldMap->getWorldMap()[this->player->getPosition()->getX()+1]
                [this->player->getPosition()->getY()]->isWalkable()) {
                this->player->getPosition()->setX((this->player->getPosition()->getX() + 1));
            }
            break;
        default:
            break;
    }

    // Check for Random Encounter?
    MapCell*** map = worldMap->getWorldMap();
    auto x = player->getPosition()->getX();
    auto y = player->getPosition()->getY();
    if (map[x][y]->isRandomEncounterable()) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<double> dist(0.0, 10.0);
        int random_number = dist(mt); // Between 0 and 9
        if (random_number == 1) {
            cout << "eat my shorts" << endl;
            // initiate a battle sequence
//            std::random_device rd;
//            std::mt19937 mt(rd());
//            cout << "eat my shorts" << endl;
//            std::uniform_real_distribution<int> dist(0, this->getWorldMap().getCurSize());
//            cout << "eat my shorts" << endl;
//            int random_enemy = dist(mt);
//            cout << "eat my shorts" << endl;
            this->curEnemy = this->getWorldMap().getEnemies()[0];
            this->gameState = BATTLE;
            this->curMenuOption = 0;
        }
    }
}

EnemyUnit World::getEnemyUnit() {
    return *this->curEnemy;
}

void World::setCurrentGameState(game_state_t newGameState) {
    this->gameState = newGameState;
}

World::~World() {
    delete this->player;
    delete this->worldMap;
}
