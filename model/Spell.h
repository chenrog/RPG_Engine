//
// Created by whyar on 11/6/2017.
//
#ifndef CS3520_2017FA_PROJ_SPELLS_H
#define CS3520_2017FA_PROJ_SPELLS_H

class IUnit;

class Spell {
public:
    Spell(int base_damage, int mod_damage, int base_hit_chance, int mod_hit_chance, bool damage_type);

    int  getDamage(const IUnit & unit);
    int  getHitChance(const IUnit & unit);
    bool getDamageType();

private:
    int  level;
    int  base_damage;
    int  mod_damage;
    int  base_hit_chance;
    int  mod_hit_chance;
    bool damage_type;
};

#endif //CS3520_2017FA_PROJ_SPELLS_H
