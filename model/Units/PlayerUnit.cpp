#include <cstdlib>
#include <ctime>
#include <iostream>
#include "PlayerUnit.h"
#include "../Equipment.h"


using namespace std;

PlayerUnit::PlayerUnit(unsigned int vit, unsigned int intel, unsigned int speed, unsigned int str,
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

PlayerUnit::PlayerUnit(unsigned int vit, unsigned int intel, unsigned int dex, unsigned int str,
                                 Equipment equipment[], Spell spell[], double mod_vit,
                                 double mod_int, double mod_str, double mod_speed, bool is_melee, unsigned int lvl) {
    this->name = name;
    this->st_vit = vit;
    this->st_intel = intel;
    this->st_speed = st_speed;
    this->st_str = str;
    this->mod_vit = mod_vit;
    this->mod_int = mod_int;
    this->mod_str = mod_str;
    this->mod_speed = mod_speed;
    this->is_melee = is_melee;
    this->lvl = lvl;
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
    this->p_defense = st_vit * 10 + st_speed;
    this->m_defense = st_intel * 10 + st_speed;
}

Equipment PlayerUnit::Equip(Equipment const equipment) {
    Equipment curEquip = this->equip[equipment.getType()];
    this->st_str -= curEquip.getStr();
    this->st_vit -= curEquip.getVit();
    this->st_intel -= curEquip.getIntel();
    this->st_speed -= curEquip.getSpeed();

    // have something here that moves the current equipment into the world inventory;

    this->st_str += equipment.getStr();
    this->st_vit += equipment.getVit();
    this->st_intel += equipment.getIntel();
    this->st_speed += equipment.getSpeed();
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
        this->st_speed += (lowest + int(range * rand() / (RAND_MAX + 1.0))) * mod_speed;
        this->st_str += (lowest + int(range * rand() / (RAND_MAX + 1.0))) * mod_str;
        updateStats();
        return true;
    } else {
        return false;
    }
}

