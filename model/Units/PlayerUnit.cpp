#include <cstdlib>
#include <ctime>
#include <iostream>
#include "PlayerUnit.h"
#include "../Equipment/Equipment.h"


using namespace std;

PlayerUnit::PlayerUnit(string name, Point position, bool visible, unsigned int vit, unsigned int intel,
                       unsigned int dex, unsigned int str, unsigned int lvl, bool is_melee, Equipment *equipment,
                       Spell *spell, double mod_vit, double mod_int, double mod_speed, double mod_dex) {
    this->name = name;
    this->position = position;
    this->visible = visible;
    this->st_vit = vit;
    this->st_intel = intel;
    this->st_dex = dex;
    this->st_str = str;
    this->mod_vit = mod_vit;
    this->mod_int = mod_int;
    this->mod_str = mod_str;
    this->mod_dex = mod_dex;
    this->is_melee = is_melee;
    this->lvl = lvl
    updateStats();
    this->health = this->max_health;
    this->mana = this->max_mana;

    updateStats();

    this->equip = equipment;
    this->spells = spell;
}

PlayerUnit::~PlayerUnit() {
    delete[] this->spells;
    delete[] this->equip;
}

void PlayerUnit::updateStats() {
    this->max_health = st_vit * 100;
    this->max_mana = st_intel * 100;
    this->p_defense = st_vit * 10 + st_dex;
    this->m_defense = st_intel * 10 + st_dex;
}

Equipment PlayerUnit::Equip(Equipment const equipment) {
    Equipment curEquip = this->equip[equipment.getType()];
    this->st_str -= curEquip.getStr();
    this->st_vit -= curEquip.getVit();
    this->st_intel -= curEquip.getIntel();
    this->st_dex -= curEquip.getSpeed();

    // have something here that moves the current equipment into the world inventory;

    this->st_str += equipment.getStr();
    this->st_vit += equipment.getVit();
    this->st_intel += equipment.getIntel();
    this->st_dex += equipment.getSpeed();
    this->equip[equipment.getType()] = equipment;
    updateStats();
}

bool PlayerUnit::addEXP(int const exp) {
    int new_exp = this->exp + exp;
    if (new_exp >= 100) {
        this->exp %= 100;
        lvl += 1;
        srand((unsigned) time(nullptr));
        int lowest = 1, highest = 10;
        int range = (highest - lowest) + 1;
        this->st_vit += (lowest + int(range * rand() / (RAND_MAX + 1.0))) * mod_vit;
        this->st_intel += (lowest + int(range * rand() / (RAND_MAX + 1.0))) * mod_int;
        this->st_dex += (lowest + int(range * rand() / (RAND_MAX + 1.0))) * mod_dex;
        this->st_str += (lowest + int(range * rand() / (RAND_MAX + 1.0))) * mod_str;
        updateStats();
        return true;
    } else {
        return false;
    }
}

