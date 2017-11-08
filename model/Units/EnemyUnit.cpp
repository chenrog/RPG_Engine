#include "EnemyUnit.h"

EnemyUnit::EnemyUnit(unsigned int vit, unsigned int intel, unsigned int speed, unsigned int str,
                       double mod_vit, double mod_int, double mod_speed, double mod_str, bool is_melee,
                       string name) {
    this->name = name;
    this->vit = vit;
    this->intel = intel;
    this->speed = speed;
    this->str = str;
    this->mod_vit = mod_vit;
    this->mod_int = mod_int;
    this->mod_str = mod_str;
    this->mod_speed = mod_speed;
    this->is_melee = is_melee;
    this->curr_health = this->health;
    this->cur_mana = this->mana;
    this->lvl = 1;

    updateStats();
}