#include <cstdlib>
#include <ctime>
#include <iostream>
#include "PlayerUnit.h"


using namespace std;

PlayerUnit::PlayerUnit(string name, Point position, bool visible, unsigned int vit, unsigned int intel, unsigned int dex,
                       unsigned int str,  unsigned int lvl, bool is_melee, Equipment equipment[], Spell spell[], double mod_vit, double mod_int,
                       double mod_dex, double mod_str) {
    this->name = name;
    this->st_vit = vit;
    this->st_intel = intel;
    this->st_speed = st_speed;
    this->st_str = str;
    this->mod_vit = mod_vit;
    this->mod_int = mod_int;
    this->mod_str = mod_str;
    this->mod_dex = mod_dex;
    this->is_melee = is_melee;
    this->lvl = lvl;
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
        this->st_vit += rand() % 10 * mod_vit;
        this->st_intel += rand() % 10 * mod_int;
        this->st_speed += rand() % 10 * mod_dex;
        this->st_str += rand() % 10 * mod_str;
        updateStats();
        return true;
    } else {
        return false;
    }
}

