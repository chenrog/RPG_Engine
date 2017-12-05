#include <random>
#include "AUnit.h"

AUnit::AUnit() = default;

AUnit::AUnit(const AUnit &unit) = default;

AUnit::~AUnit() = default;

int AUnit::takeDamage(Spell * s, AUnit* attacker) {
//    std::random_device rd;
//    std::mt19937 mt(rd());
//    std::uniform_real_distribution<double> dist(0, 100);
    double hit_roll = 100;
    // calculate if the attack hits
    if ((int) hit_roll < s->getHitChance(attacker)) {

        // calculate this unit's damage mitigation
        unsigned int defense;
        // if the damage will be physical
        if (s->getDamageType() == PHYSICAL) {
            defense = p_defense;
        }
        // if the damage will be magical
        else {
            defense = m_defense;
        }

        // calculate the damage

        int damage = (int)((float)s->getDamage(attacker) * (float)(100.0 / (100.0 + defense)));
        cout << attacker->getName() << " DID " << damage << " DAMAGE!" << endl;
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

Spell ** AUnit::getSpells() const {
    return spellList;
}

void AUnit::addSpell(Spell *spell) {
    if (curSpellSize < 4) {
        this->spellList[this->curSpellSize] = spell;
        curSpellSize++;
    }
}

Spell * AUnit::getSpell(unsigned int i) const {
    return (spellList)[i];
}

void AUnit::reset(){
    this->health = this->max_health;
    this->mana = this->max_mana;
}

void AUnit::updateStats() {
    this->max_health = st_vit * 100;
    this->max_mana = st_int * 100;
    this->p_defense = st_vit * 10 + st_dex;
    this->m_defense = st_int * 10 + st_dex;
}