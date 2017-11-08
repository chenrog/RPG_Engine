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
    this->vit = vit;
    this->intel = intel;
    this->speed = speed;
    this->str = str;
    this->mod_vit = mod_vit;
    this->mod_int = mod_int;
    this->mod_str = mod_str;
    this->mod_speed = mod_speed;
    this->is_melee = is_melee;
    updateStats();
    this->curr_health = this->health;
    this->cur_mana = this->mana;
    this->lvl = 1;
}

PlayerUnit::PlayerUnit(unsigned int vit, unsigned int intel, unsigned int dex, unsigned int str,
                                 Equipment equipment[], Spell spell[], double mod_vit,
                                 double mod_int, double mod_str, double mod_speed, bool is_melee, unsigned int lvl) {
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
    this->lvl = lvl;
    updateStats();
    this->curr_health = this->health;
    this->cur_mana = this->mana;

    updateStats();

    this->equip = equipment;
    this->spells = spell;
}

PlayerUnit::~PlayerUnit() {
    delete[] this->spells;
    delete[] this->equip;
}

void PlayerUnit::updateStats() {
    this->health = vit * 100;
    this->mana = intel * 100;
    this->p_defense = vit * 10 + speed;
    this->m_defense = intel * 10 + speed;
}

Equipment PlayerUnit::Equip(Equipment const equipment) {
    Equipment curEquip = this->equip[equipment.getType()];
    this->str -= curEquip.getStr();
    this->vit -= curEquip.getVit();
    this->intel -= curEquip.getIntel();
    this->speed -= curEquip.getSpeed();

    // have something here that moves the current equipment into the world inventory;

    this->str += equipment.getStr();
    this->vit += equipment.getVit();
    this->intel += equipment.getIntel();
    this->speed += equipment.getSpeed();
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
        this->vit += (lowest + int(range * rand() / (RAND_MAX + 1.0))) * mod_vit;
        this->intel += (lowest + int(range * rand() / (RAND_MAX + 1.0))) * mod_int;
        this->speed += (lowest + int(range * rand() / (RAND_MAX + 1.0))) * mod_speed;
        this->str += (lowest + int(range * rand() / (RAND_MAX + 1.0))) * mod_str;
        updateStats();
        return true;
    } else {
        return false;
    }
}

