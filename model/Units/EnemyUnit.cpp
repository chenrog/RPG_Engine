#include "EnemyUnit.h"

EnemyUnit::EnemyUnit(unsigned int vit, unsigned int intel, unsigned int speed, unsigned int str, bool is_melee,
                       string name, tuple<int, Item> drops) {
    this->name = name;
    this->vit = vit;
    this->intel = intel;
    this->speed = speed;
    this->str = str;
    this->is_melee = is_melee;
    this->curr_health = this->health;
    this->cur_mana = this->mana;
    this->drop = drops;

    updateStats();
}