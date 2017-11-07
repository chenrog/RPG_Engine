#include <cstdlib>
#include <time.h>
#include <iostream>
#include "PlayerCharacter.h"
#include "Equipment.h"
#include "Spell.h"

using namespace std;

PlayerCharacter::PlayerCharacter(unsigned int vit, unsigned int intel, unsigned int speed, unsigned int str,
                                 double mod_vit, double mod_int, double mod_speed, double mod_str, bool is_melee,
                                 string name) {
    move(name);
    this->vit = vit;
    this->intel = intel;
    this->speed = speed;
    this->str = str;
    this->mod_vit = mod_vit;
    this->mod_int = mod_int;
    this->mod_str = mod_str;
    this->mod_speed = mod_speed;
    this->is_melee = is_melee;
    this->lvl = 1;

    updateStats();
}

PlayerCharacter::PlayerCharacter(unsigned int vit, unsigned int intel, unsigned int dex, unsigned int str,
                                 Equipment equipment[], Spell spell[], double mod_vit,
                                 double mod_int, double mod_str, double mod_speed, bool is_melee, unsigned int lvl) {
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

    // to be refined later
    this->equip = equipment;
    this->spells = spell;
}

void PlayerCharacter::updateStats() {
    this->health = vit * 100;
    this->mana = intel * 100;
    this->p_defense = vit * 10 + speed;
    this->m_defense = intel * 10 + speed;
}

int PlayerCharacter::takeDamage(const int damage, int hit_chance, bool is_physical) {
    if (is_physical) {
        int damage_taken = (damage - p_defense);
        if (hit_chance <= 1 + int((100 * -1) * rand() / (RAND_MAX + 1.0))) {
            health -= damage_taken;
            return damage_taken;
        } else {
            return 0;
        }
    } else {
        int damage_taken = (damage - m_defense);
        health -= damage_taken;
        return damage_taken;
    }
}

Equipment PlayerCharacter::Equip(Equipment const equipment) {

}

bool PlayerCharacter::addEXP(int const exp) {
    int new_exp = this->exp + exp;
    if (new_exp >= 100) {
        this->exp %= 100;
        lvl += 1;
        srand((unsigned) time(nullptr));
        int lowest = 1, highest = 10;
        int range = (highest - lowest) + 1;
        this->mod_vit += lowest + int(range * rand() / (RAND_MAX + 1.0)) * mod_vit;
        this->mod_int += lowest + int(range * rand() / (RAND_MAX + 1.0)) * mod_int;
        this->mod_speed += lowest + int(range * rand() / (RAND_MAX + 1.0)) * mod_speed;
        this->mod_str += lowest + int(range * rand() / (RAND_MAX + 1.0)) * mod_str;
        updateStats();
        return true;
    } else {
        return false;
    }
}

int PlayerCharacter::basicAttack(bool is_physical) {
    if (is_physical) {
        return this->str * 10;
    } else {
        return this->intel * 10;
    }
}