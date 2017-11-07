#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter(unsigned int vit, unsigned int intel, unsigned int speed, unsigned int str) {
    this->vit = vit;
    this->intel = intel;
    this->speed = speed;
    this->str = str;

    updateStats();
}

PlayerCharacter::PlayerCharacter(unsigned int vit, unsigned int intel, unsigned int dex, unsigned int str,
                                 Equipment equipment[], Spell spell[]) {
    this->vit = vit;
    this->intel = intel;
    this->speed = speed;
    this->str = str;

    updateStats();

    // to be refined later
    this->equip = equipment;
    this->spells = spell;
}

void PlayerCharacter::updateStats() {
    this->health = vit * 100;
    this->mana = intel * 100;
    this->p_defense = vit * speed * 10;
    this->m_defense = intel * speed * 10;
}

void PlayerCharacter::takeDamage(const int damage, bool is_physical) {
    if (is_physical) {
        health -= health - (damage - p_defense);
    } else {
        health -= health - (damage - m_defense);
    }
}

void PlayerCharacter::addEXP(int const exp) {
    int new_exp = this->exp + exp;
    if (new_exp >= 100) {
        this->exp %= 100;
    }
}

int PlayerCharacter::basicAttack(bool is_physical) {
    return this->str;
}