#include <random>
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

int AUnit::takeDamage(Spell s, AUnit attacker) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<int> dist(0, 100);
    int hit_roll = dist(mt);

    // calculate if the attack hits
    if (hit_roll < s.getHitChance(attacker)) {
        // calculate this unit's damage mitigation
        unsigned int defense;
        // if the damage will be physical
        if (s.getDamageType() == PHYSICAL) {
            defense = p_defense;
        }
        // if the damage will be magical
        else {
            defense = m_defense;
        }

        // calculate the damage
        int damage = (float)s.getDamage(attacker) * (float)(100 / 100 + defense);
        if (this->health >= damage) {
            this->health -= damage;
        } else {
            this->health = 0;
        }

        return damage;
    }

    else {
        return 0;
    }
}

int AUnit::calcBasicAttack() {
    if (this->melee) {
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

unsigned int AUnit::get_lvl() const {
    return this->lvl;
}

bool AUnit::is_melee() const {
    return this->melee;
}

vector<Spell> AUnit::getSpells() const {
    return *spellList;
}

Spell AUnit::getSpell(unsigned int i) const {
    return (*spellList)[i];
}

void AUnit::updateStats() {
    this->max_health = st_vit * 100;
    this->max_mana = st_int * 100;
    this->p_defense = st_vit * 10 + st_dex;
    this->m_defense = st_int * 10 + st_dex;
}