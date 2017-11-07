//
// Created by Roger Chen on 11/6/17.
//

#include "Equipment.h"
#include <iostream>
#include <string>
#include <cassert>
#include <utility>

using namespace std;

Equipment::Equipment(string name, unsigned int type, signed int v, unsigned int vm, signed int i, unsigned int im,
                     signed int sp, unsigned int spm, signed int st, unsigned int stm) :
        name(std::move(name)), level(0), type(type), vit(v), vit_mod(vm), intel(i), int_mod(im), speed(sp),
        speed_mod(spm), str(st), str_mod(stm) { }

void Equipment::level_up() {
    this->level += 1;
    this->vit += vit_mod;
    this->intel += int_mod;
    this->speed += speed_mod;
    this->str += str_mod;
}

void Equipment::display() {
    string type;

    // this determines what to output based on the equipment type
    switch (this->type) {
        case Helmet :
            type = "Helmet";
        case Armor :
            type = "Armor";
        case Boots :
            type = "Boots";
        case Primary :
            type = "Weapon";
        case Offhand :
            type = "Offhand";
    }

    cout << "{ " << type << " - " << this->name;

    if (this->level > 0) {
        cout << "+" << this->level;
    }

    cout << ": ";
    cout << "VITALITY(" << this->vit << "), ";
    cout << "INTELLIGENCE(" << this->intel << "), ";
    cout << "STRENGTH(" << this->str << "), ";
    cout << "SPEED(" << this->speed << ") }" << endl;
}

class Equip_Builder {
public:
    Equip_Builder(string name, unsigned int type) : name(std::move(name)), type(type) { }

    // this builds a new Equipment with the stats of this equipment
    Equipment & build() {
        assert(0 <= type < 5);
        auto equipment = new Equipment(name, type, vit, vit_mod, intel, int_mod, speed, speed_mod, str, str_mod);
        return *equipment;
    }

    Equip_Builder & setName(const string &name) {
        Equip_Builder::name = name;
        return *this;
    }

    Equip_Builder setType(unsigned int type) {
        Equip_Builder::type = type;
        return *this;
    }

    Equip_Builder setVit(int vit) {
        Equip_Builder::vit = vit;
        return *this;
    }

    Equip_Builder setVit_mod(unsigned int vit_mod) {
        Equip_Builder::vit_mod = vit_mod;
        return *this;
    }

    Equip_Builder setIntel(int intel) {
        Equip_Builder::intel = intel;
        return *this;
    }

    Equip_Builder setInt_mod(unsigned int int_mod) {
        Equip_Builder::int_mod = int_mod;
        return *this;
    }

    Equip_Builder setSpeed(int speed) {
        Equip_Builder::speed = speed;
        return *this;
    }

    Equip_Builder setSpeed_mod(unsigned int speed_mod) {
        Equip_Builder::speed_mod = speed_mod;
        return *this;
    }

    Equip_Builder setStr(int str) {
        Equip_Builder::str = str;
        return *this;
    }

    Equip_Builder setStr_mod(unsigned int str_mod) {
        Equip_Builder::str_mod = str_mod;
        return *this;
    }

private:
    string       name;
    unsigned int type;

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
