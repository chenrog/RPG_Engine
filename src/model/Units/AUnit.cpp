#include "AUnit.h"

AUnit::AUnit() {}

AUnit::AUnit(const AUnit &unit) {}

AUnit::~AUnit() {}

void AUnit::move(direction_t direction, unsigned int distance) {
    //TODO: Add prevention of going OOB in world.
    switch (direction) {
        case UP:
            this->position.setY(this->position.getY() + distance);
            break;
        case DOWN:
            this->position.setY(this->position.getY() - distance);
            break;
        case LEFT:
            this->position.setX(this->position.getX() - distance);
            break;
        case RIGHT:
            this->position.setX(this->position.getX() + distance);
            break;
        default:
            break;
    }
}

int AUnit::takeDamage(int damage, int hit_chance, bool is_physical) {
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

int AUnit::calcBasicAttack() {
    if (this->is_melee) {
        return this->st_str * 10;
    } else {
        return this->st_int * 10;
    }
}

unsigned int AUnit::get_health() const {
    return this->health;
}

unsigned int AUnit::get_max_health() const {
    return this->max_health;
}

unsigned int AUnit::get_mana() const {
    return this->mana;
}

unsigned int AUnit::get_max_mana() const {
    return this->max_mana;
}

unsigned int AUnit::get_p_def() const {
    return this->p_defense;
}

unsigned int AUnit::get_m_def() const {
    return this->m_defense;
}

unsigned int AUnit::get_vit() const {
    return this->st_vit;
}

unsigned int AUnit::get_int() const {
    return this->st_int;
}

unsigned int AUnit::get_dex() const {
    return this->st_dex;
}

unsigned int AUnit::get_str() const {
    return this->st_str;
}

void AUnit::updateStats() {
    this->max_health = st_vit * 100;
    this->max_mana = st_int * 100;
    this->p_defense = st_vit * 10 + st_dex;
    this->m_defense = st_int * 10 + st_dex;
}
