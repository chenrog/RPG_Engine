#include "IUnit.h"

IUnit::IUnit() {}

IUnit::IUnit(const IUnit &unit) {}

IUnit::~IUnit() {}

int IUnit::takeDamage(int damage, int hit_chance, bool is_physical) {
    if (is_physical) {
        if (hit_chance <= 1 + int((100 * -1) * rand() / (RAND_MAX + 1.0))) {
            int damage_taken = (damage - p_defense);
            this->curr_health -= damage_taken;
            return damage_taken;
        } else {
            return 0;
        }
    } else {
        int damage_taken = (damage - m_defense);
        this->curr_health -= damage_taken;
        return damage_taken;
    }
}

int IUnit::calcBasicAttack() {
    if (this->is_melee) {
        return this->str * 10;
    } else {
        return this->intel * 10;
    }
}

int IUnit::getX(const IUnit &unit) {
    return unit.pos_x;
}

int IUnit::getY(const IUnit &unit) {
    return unit.pos_y;
}

void IUnit::setX(int x) {
    this->pos_x = x;
}

void IUnit::setY(int y) {
    this->pos_y = y;
}