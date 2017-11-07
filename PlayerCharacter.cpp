#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter(unsigned int vit,unsigned int intel,unsigned int speed,unsigned int str) {
    this->vit = vit;
    this->intel = intel;
    this->speed = speed;
    this->str = str;

    // Derived stats TO BE BALANCED LATER
    this->health = vit * 100;
    this->mana = intel * 100;
    this->p_defense = vit * speed * 10;
    this->m_defense = intel * speed * 10;
}

PlayerCharacter::PlayerCharacter(unsigned int vit, unsigned int intel, unsigned int dex, unsigned int str,
                                 Equipment equipment[], Spell spell[]) {
    this->vit = vit;
    this->intel = intel;
    this->speed = speed;
    this->str = str;

    // Derived stats TO BE BALANCED LATER
    this->health = vit * 100;
    this->mana = intel * 100;
    this->p_defense = vit * speed * 10;
    this->m_defense = intel * speed * 10;

    //
    this->equip = equipment;
    this->spells = spell;
}