//
// Created by whyar on 11/6/2017.
//
#ifndef CS3520_2017FA_PROJ_SPELLS_H
#define CS3520_2017FA_PROJ_SPELLS_H

#include "DamageType.h"
#include <string>
#ifndef CS3520_2017FA_PROJ_UNIT_H
#include "../Units/IUnit.h"
#include "SpellType.h"
#include "TargetType.h"

#endif //CS3520_2017FA_PROJ_UNIT_H

using namespace std;

class Spell {
public:
    Spell(string spell, int base_damage, int mod_damage, int base_hit_chance, int mod_hit_chance,
          spell_type_t spell_type, damage_type_t damage_type, target_type_t target_type);
    friend Spell & build();

    int  getDamage(const IUnit & unit);
    int  getHitChance(const IUnit & unit);
    spell_type_t  getSpellType();
    damage_type_t getDamageType();
    target_type_t getTargetType();

    void display();

private:
    string        spellname;
    int           base_damage;
    int           mod_damage;
    int           base_hit_chance;
    int           mod_hit_chance;
    spell_type_t  spell_type;
    damage_type_t damage_type;
    target_type_t target_type;
};


class Spell_Builder {
public:
    // builder constructor and build function
    Spell_Builder(string spell, spell_type_t spell_type, damage_type_t damage_type, target_type_t target_type);
    Spell & build();
    // setters for the fields
    Spell_Builder setDamage(int damage);
    Spell_Builder setDamageMod(int damage_mod);
    Spell_Builder setHitChance(int chance);
    Spell_Builder setHitChanceMod(int chance_mod);

private:

    string        spellname;
    int           base_damage = 0;
    int           mod_damage = 1;
    int           base_hit_chance = 100;
    int           mod_hit_chance = 1;
    spell_type_t  spell_type;
    damage_type_t damage_type;
    target_type_t target_type;
};
#endif //CS3520_2017FA_PROJ_SPELLS_H
