#include "EnemyUnit.h"

EnemyUnit::EnemyUnit(unsigned int vit, unsigned int intel, unsigned int speed, unsigned int str, bool is_melee,
                     string name, Item drops[]) {
    this->name = name;
    this->st_vit = vit;
    this->st_intel = intel;
    this->st_speed = speed;
    this->st_str = str;
    this->is_melee = is_melee;
    updateStats();
    this->health = this->max_health;
    this->mana = this->max_mana;
    this->lvl = 1;
    this->drop = drops;
}

EnemyUnit::EnemyUnit(const EnemyUnit &unit) {
    this->name = name;
    this->st_vit = unit.st_vit;
    this->st_intel = unit.st_intel;
    this->st_speed = unit.st_speed;
    this->st_str = unit.st_str;
    this->is_melee = is_melee;
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
    int random_int = rand() % 10;
    return this->drop[random_int];
}
