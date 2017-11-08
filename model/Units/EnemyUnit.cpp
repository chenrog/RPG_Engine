#include "EnemyUnit.h"

EnemyUnit::EnemyUnit(unsigned int vit, unsigned int intel, unsigned int speed, unsigned int str,
                       double mod_vit, double mod_int, double mod_speed, double mod_str, bool is_melee,
                       string name) {
    this->name = name;
    this->st_vit = vit;
    this->st_intel = intel;
    this->st_speed = speed;
    this->st_str = str;
    this->mod_vit = mod_vit;
    this->mod_int = mod_int;
    this->mod_str = mod_str;
    this->mod_speed = mod_speed;
    this->is_melee = is_melee;
    this->health = this->max_health;
    this->mana = this->max_mana;
    this->lvl = 1;

    updateStats();
}