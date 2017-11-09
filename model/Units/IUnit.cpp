#include "IUnit.h"

IUnit::IUnit() {}

IUnit::IUnit(const IUnit &unit) {}

IUnit::~IUnit() {}

int IUnit::takeDamage(int damage, int hit_chance, bool is_physical) {
    if (is_physical) {
        if (hit_chance <= 1 + int((100 * -1) * rand() / (RAND_MAX + 1.0))) {
            int damage_taken = (damage - p_defense);
            this->health -= damage_taken;
            return damage_taken;
        } else {
            return 0;
        }
    } else {
        int damage_taken = (damage - m_defense);
        this->health -= damage_taken;
        return damage_taken;
    }
}

int IUnit::calcBasicAttack() {
    if (this->is_melee) {
        return this->st_str * 10;
    } else {
        return this->st_int * 10;
    }
}

unsigned int IUnit::get_health() const{
    return this->health;
}
unsigned int IUnit::get_max_health() const{
    return this->max_health;
}
unsigned int IUnit::get_mana() const{
    return this->mana;
}
unsigned int IUnit::get_max_mana() const{
    return this->max_mana;
}
unsigned int IUnit::get_p_def() const{
    return this->p_defense;
}
unsigned int IUnit::get_m_def() const{
    return this->m_defense;
}
unsigned int IUnit::get_vit() const{
    return this->st_vit;
}
unsigned int IUnit::get_int() const{
    return this->st_int;
}
unsigned int IUnit::get_dex() const{
    return this->st_dex;
}
unsigned int IUnit::get_str() const{
    return this->st_str;
}
