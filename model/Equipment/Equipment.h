#ifndef CS3520_2017FA_PROJ_EQUIPMENT_H
#define CS3520_2017FA_PROJ_EQUIPMENT_H

#include "EquipType.h"
#include "../Units/AEntity.h"
#include <string>

using namespace std;

class Equipment : public AEntity{
public:
    Equipment(string name, Point position, bool visible, equip_type_t type, signed int v, unsigned int vm, signed int i,
              unsigned int im, signed int sp, unsigned int spm, signed int st, unsigned int stm);
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
    // speed stats by this equipment
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
    Equipment & buildEquip();
    // setters for the fields
    Equip_Builder setName(const string &name);
    Equip_Builder setPosition(const Point &position);
    Equip_Builder setVisibility(const bool &visibility);
    Equip_Builder setVit(int vit);
    Equip_Builder setVit_mod(unsigned int vit_mod);
    Equip_Builder setIntel(int intel);
    Equip_Builder setInt_mod(unsigned int int_mod);
    Equip_Builder setSpeed(int speed);
    Equip_Builder setSpeed_mod(unsigned int speed_mod);
    Equip_Builder setStr(int str);
    Equip_Builder setStr_mod(unsigned int str_mod);

private:
    string       name;
    Point        position = NULL;
    bool         visible = false;
    equip_type_t type;
    // vitality stats by this equipment
    signed int   vit = 0;
    unsigned int vit_mod = 0;
    // intelligence stats by this equipment
    signed int   intel = 0;
    unsigned int int_mod = 0;
    // speed stats by this equipment
    signed int   speed = 0;
    unsigned int speed_mod = 0;
    // strength stats by this equipment
    signed int   str = 0;
    unsigned int str_mod = 0;
};

#endif //CS3520_2017FA_PROJ_EQUIPMENT_H
