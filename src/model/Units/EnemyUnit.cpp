#include "EnemyUnit.h"
#include <random>

EnemyUnit::EnemyUnit() { }

EnemyUnit::EnemyUnit(unsigned int vit, unsigned int intel, unsigned int speed, unsigned int str, bool melee,
                     string name, vector<Item> drops) {
    this->name = name;
    this->st_vit = vit;
    this->st_int = intel;
    this->st_dex = speed;
    this->st_str = str;
    this->melee = melee;
    updateStats();
    this->health = this->max_health;
    this->mana = this->max_mana;
    this->drop = drops;
    this->visible = false;
}

EnemyUnit::EnemyUnit(Posn posn, unsigned int vit, unsigned int intel, unsigned int speed, unsigned int str, bool melee,
                     string name, vector<Item> drops) {
    this->position = posn;
    this->name = name;
    this->st_vit = vit;
    this->st_int = intel;
    this->st_dex = speed;
    this->st_str = str;
    this->melee = melee;
    updateStats();
    this->health = this->max_health;
    this->mana = this->max_mana;
    this->drop = drops;
    this->visible = false;
}

EnemyUnit::EnemyUnit(const EnemyUnit &unit) {
    this->name = name;
    this->st_vit = unit.st_vit;
    this->st_int = unit.st_int;
    this->st_dex = unit.st_dex;
    this->st_str = unit.st_str;
    this->melee = melee;
    updateStats();
    this->health = this->max_health;
    this->mana = this->max_mana;
    this->lvl = 1;
    int i = 0;
    for (Item drop : unit.drop) {
        this->drop[i] = drop;
        i++;
    }
}

Item EnemyUnit::calcDrop() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, drop.size());
    int random_int = dist(mt);
    return this->drop[random_int];
}
