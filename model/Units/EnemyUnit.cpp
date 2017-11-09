#include "EnemyUnit.h"

EnemyUnit::EnemyUnit(unsigned int vit, unsigned int intel, unsigned int speed, unsigned int str, bool is_melee,
                       string name, tuple<int, Item> drops) {
    this->name = name;
    this->st_vit = vit;
    this->st_int = intel;
    this->st_dex = speed;
    this->st_str = str;
    this->is_melee = is_melee;
    updateStats();
    this->health = this->max_health;
    this->mana = this->max_mana;
    this->lvl = 1;
    this->drop = drops;
}
