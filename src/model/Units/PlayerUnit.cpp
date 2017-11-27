#include "PlayerUnit.h"



using namespace std;

PlayerUnit::PlayerUnit(string name, Point position, bool visible, unsigned int vit, unsigned int intel, unsigned int dex,
                       unsigned int str,  unsigned int lvl, bool is_melee, vector<Equipment> equipment,
                       vector<Spell> spell, double mod_vit, double mod_int, double mod_dex, double mod_str) {
    this->name = name;
    this->st_vit = vit;
    this->st_int = intel;
    this->st_dex = dex;
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

    this->equipmentList = equipment;
    this->spellList = spell;
}

Equipment PlayerUnit::equip(Equipment const equipment) {
    Equipment curEquip = this->equipmentList[equipment.getType()];
    this->st_str -= curEquip.getStr();
    this->st_vit -= curEquip.getVit();
    this->st_int -= curEquip.getIntel();
    this->st_dex -= curEquip.getSpeed();

    // have something here that moves the current equipment into the world inventory;

    this->st_str += equipment.getStr();
    this->st_vit += equipment.getVit();
    this->st_int += equipment.getIntel();
    this->st_dex += equipment.getSpeed();
    this->equipmentList[equipment.getType()] = equipment;
    updateStats();
}

bool PlayerUnit::addEXP(int const exp) {
    int new_exp = this->exp + exp;
    if (new_exp >= 100) {
        this->exp %= 100;
        lvl += 1;
        this->st_vit += rand() % 10 * mod_vit;
        this->st_int += rand() % 10 * mod_int;
        this->st_dex += rand() % 10 * mod_dex;
        this->st_str += rand() % 10 * mod_str;
        updateStats();
        return true;
    } else {
        return false;
    }
}
