//
// Created by whyar on 11/6/2017.
//
#ifndef CS3520_2017FA_PROJ_SPELLS_H
#define CS3520_2017FA_PROJ_SPELLS_H


#ifndef CS3520_2017FA_PROJ_UNIT_H
#include "../Units/AUnit.h"
#endif //CS3520_2017FA_PROJ_UNIT_H

#include "DamageType.h"
#include "SpellType.h"
#include <string>


class AUnit;

using namespace std;

class Spell {
public:
    Spell(string spell, int base_damage, int mod_damage, int base_hit_chance, int mod_hit_chance,
          spell_type_t spell_type, damage_type_t damage_type);

    int getDamage(const AUnit* unit);
    int getHitChance(const AUnit* unit);
    spell_type_t  getSpellType();
    damage_type_t getDamageType();

    void display();

    string getName();

private:
    string        spellname;
    int           base_damage;
    int           mod_damage;
    int           base_hit_chance;
    int           mod_hit_chance;
    spell_type_t  spell_type;
    damage_type_t damage_type;
};


class Spell_Builder {
public:
    // builder constructor and build function
    Spell_Builder(string spell, spell_type_t spell_type, damage_type_t damage_type);
    Spell * build();
    // setters for the fields
    Spell_Builder setDamage(int damage);
    Spell_Builder setDamageMod(int damage_mod);
    Spell_Builder setHitChance(int chance);
    Spell_Builder setHitChanceMod(int chance_mod);

private:
    string        spellname;
    int           base_damage;
    int           mod_damage;
    int           base_hit_chance;
    int           mod_hit_chance;
    spell_type_t  spell_type;
    damage_type_t damage_type;
};
#endif //CS3520_2017FA_PROJ_SPELLS_H
