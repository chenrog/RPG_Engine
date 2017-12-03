#ifndef CS3520_2017FA_PROJ_EQUIPMENT_H
#define CS3520_2017FA_PROJ_EQUIPMENT_H

#include "EquipType.h"
#include "../Item.h"
#include <string>

using namespace std;

class Equipment : public Item{
public:
    Equipment(string name, Posn position, bool visible, equip_type_t type, signed int v, unsigned int vm, signed int i,
              unsigned int im, signed int sp, unsigned int spm, signed int st, unsigned int stm, string description);
    // functions
    void level_up();
    void display();
    // getters to return the value of the given stat
    equip_type_t getType() const;
    int getVit() const;
    int getStr() const;
    int getSpeed() const;
    int getIntel() const;

private:
    unsigned int level;
    equip_type_t type;
    // vitality stats by this equipment
    signed int   vit;
    unsigned int vit_mod;
    // intelligence stats by this equipment
    signed int   intel;
    unsigned int int_mod;
    // dex stats by this equipment
    signed int   speed;
    unsigned int speed_mod;
    // strength stats by this equipment
    signed int   str;
    unsigned int str_mod;
};

class Equip_Builder {
public:
    // builder constructor and build function
    Equip_Builder(string name, equip_type_t type);
    Equipment * build();
    // setters for the fields
    Equip_Builder setPosition(const Posn &position);
    Equip_Builder setVisibility(const bool &visibility);
    Equip_Builder setVit(int vit);
    Equip_Builder setVit_mod(unsigned int vit_mod);
    Equip_Builder setIntel(int intel);
    Equip_Builder setInt_mod(unsigned int int_mod);
    Equip_Builder setDex(int dex);
    Equip_Builder setDex_mod(unsigned int dex_mod);
    Equip_Builder setStr(int str);
    Equip_Builder setStr_mod(unsigned int str_mod);
    Equip_Builder setDesc(string desc);

private:
    string       name;
    Posn        position;
    bool         visible;
    equip_type_t type;
    // vitality stats by this equipment
    signed int   vit;
    unsigned int vit_mod;
    // intelligence stats by this equipment
    signed int   intel;
    unsigned int int_mod;
    // dex stats by this equipment
    signed int   dex;
    unsigned int dex_mod;
    // strength stats by this equipment
    signed int   str;
    unsigned int str_mod;
    // description of the item
    string       desc;
};

#endif //CS3520_2017FA_PROJ_EQUIPMENT_H
