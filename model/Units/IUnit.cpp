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
        return this->st_intel * 10;
    }
}

void IUnit::updateStats() {
    this->max_health = st_vit * 100;
    this->max_mana = st_intel * 100;
    this->p_defense = st_vit * 10 + st_speed;
    this->m_defense = st_intel * 10 + st_speed;
}