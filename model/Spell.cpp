//
// Created by Roger Chen on 11/8/17.
//

#include "Spell.h"

Spell::Spell(string spell, int base_damage, int mod_damage, int base_hit_chance, int mod_hit_chance, damage_type_t damage_type) :
        spellname(std::move(spell)), base_damage(base_damage), mod_damage(mod_damage), base_hit_chance(base_hit_chance),
        mod_hit_chance(mod_hit_chance), damage_type(damage_type) { }

int Spell::getDamage(const IUnit &unit) {
    int damage_stat;

    switch(this->damage_type) {
        case PHYSICAL :
            damage_stat = unit.get_str();
            break;
        case MAGICAL :
            damage_stat = unit.get_int();
    }
}