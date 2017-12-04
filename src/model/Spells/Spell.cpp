#include "Spell.h"

Spell::Spell(string spell, int base_damage, int mod_damage, int base_hit_chance, int mod_hit_chance, spell_type_t spell_type,
             damage_type_t damage_type) :
        spellname(std::move(spell)), base_damage(base_damage), mod_damage(mod_damage), base_hit_chance(base_hit_chance),
        mod_hit_chance(mod_hit_chance), spell_type(spell_type), damage_type(damage_type) { }

int Spell::getDamage(const AUnit &unit) {
    signed int total_damage;
    unsigned damage_stat = 0;

    // this determines if the damage type is physical or magical before adding base damage or ratios
    switch(this->damage_type) {
        case PHYSICAL :
            damage_stat = unit.get_str();
            break;
        case MAGICAL :
            damage_stat = unit.get_int();
            break;
    }

    total_damage = this->base_damage + (this->mod_damage * damage_stat);
    return total_damage * this->spell_type;
}

int Spell::getHitChance(const AUnit &unit) {
    unsigned int total_hit_chance = this->base_hit_chance + (this->mod_hit_chance * unit.get_dex());
    return total_hit_chance;
}

spell_type_t  Spell::getSpellType() {
    return this->spell_type;
}
damage_type_t Spell::getDamageType() {
    return this->damage_type;
}

void Spell::display() {
    string spell_type;
    string damage_type;
    string scaling_stat;

    // physical or magical ability
    switch(this->damage_type) {
        case PHYSICAL :
            damage_type = "Physical";
            scaling_stat = "STR";
            break;
        case MAGICAL :
            damage_type = "Magical";
            scaling_stat = "INT";
            break;
    }

    // healing or damaging ability
    switch(this->spell_type) {
        case HEAL :
            spell_type = "Heal";
            break;
        case DAMAGE :
            spell_type = "Attack";
    }

    cout << "{ " << this->spellname << " - " << " " << damage_type << " " << spell_type <<  ": ";
    cout << "Damage [" << this->base_damage << " + (" << this->mod_damage << " * " << scaling_stat << ")] | ";
    cout << "HitRate [" << this->base_hit_chance << " + (" << this->mod_hit_chance << " * DEX)]" << endl;
}

// BUILDER FROM HERE ON OUT

static const int DEFAULT_BASE_DAMAGE = 0;
static const int DEFAULT_MOD_DAMAGE = 1;
static const int DEFAULT_BASE_HIT_CHANCE = 100;
static const int DEFAULT_MOD_HIT_CHANCE = 1;

Spell_Builder::Spell_Builder(string spell, spell_type_t spell_type, damage_type_t damage_type) :
        spellname(std::move(spell)), spell_type(spell_type), damage_type(damage_type),
        base_damage(DEFAULT_BASE_DAMAGE), mod_damage(DEFAULT_MOD_DAMAGE),
        base_hit_chance(DEFAULT_BASE_HIT_CHANCE), mod_hit_chance(DEFAULT_MOD_HIT_CHANCE) { }

Spell * Spell_Builder::build() {
    Spell* spell = new Spell(this->spellname, this->base_damage, this->mod_damage, this->base_hit_chance, this->mod_hit_chance,
                           this->spell_type, this->damage_type);
    return spell;
}

Spell_Builder Spell_Builder::setDamage(int damage) {
    this->base_damage = damage;
    return *this;
}
Spell_Builder Spell_Builder::setDamageMod(int damage_mod) {
    this->mod_damage = damage_mod;
    return *this;
}
Spell_Builder Spell_Builder::setHitChance(int chance) {
    this->base_hit_chance = chance;
    return *this;
}
Spell_Builder Spell_Builder::setHitChanceMod(int chance_mod) {
    this->mod_hit_chance = chance_mod;
    return *this;
}