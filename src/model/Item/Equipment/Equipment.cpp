//
// Created by Roger Chen on 11/6/17.
//

#include "Equipment.h"

using namespace std;

Equipment::Equipment(string name, Point position, bool visible, equip_type_t type, signed int v, unsigned int vm,
                     signed int i, unsigned int im, signed int sp, unsigned int spm, signed int st, unsigned int stm) :
        level(0), type(type), vit(v), vit_mod(vm), intel(i), int_mod(im), speed(sp), speed_mod(spm), str(st), str_mod(stm) {

        this->name = std::move(name);
        this->position = position;
        this->visible = visible;
}

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
        case HELMET :
            type = "Helmet";
            break;
        case ARMOR :
            type = "Armor";
            break;
        case BOOTS :
            type = "Boots";
            break;
        case PRIMARY :
            type = "Weapon";
            break;
        case OFFHAND :
            type = "Offhand";
            break;
    }

    cout << "{ " << type << " - " << this->name;

    if (this->level > 0) {
        cout << "+" << this->level;
    }

    cout << ": ";
    cout << "VITALITY(" << this->vit << "), ";
    cout << "INTELLIGENCE(" << this->intel << "), ";
    cout << "STRENGTH(" << this->str << "), ";
    cout << "DEXTERITY(" << this->speed << ") }" << endl;
}

equip_type_t Equipment::getType() const {
    return type;
}
int Equipment::getVit() const {
    return vit;
}

int Equipment::getIntel() const{
    return intel;
}

int Equipment::getSpeed() const {
    return speed;
}

int Equipment::getStr() const {
    return str;
}

Equip_Builder::Equip_Builder(string name, equip_type_t type) : name(std::move(name)), type(type) {}

// this builds a new Equipment with the stats of this equipment
Equipment * Equip_Builder::build() {
    auto equipment = new Equipment(name, position, visible, type, vit, vit_mod, intel, int_mod, speed, speed_mod, str, str_mod);
    return equipment;
}

Equip_Builder Equip_Builder::setName(const string &name) {
    this->name = std::move(name);
    return *this;
}

Equip_Builder Equip_Builder::setPosition(const Point &position) {
    this->position = position;
    return *this;
}
Equip_Builder Equip_Builder::setVisibility(const bool &visible) {
    this->visible = visible;
    return *this;
}

Equip_Builder Equip_Builder::setVit(int vit) {
    this->vit = vit;
    return *this;
}

Equip_Builder Equip_Builder::setVit_mod(unsigned int vit_mod) {
    this->vit_mod = vit_mod;
    return *this;
}

Equip_Builder Equip_Builder::setIntel(int intel) {
    this->intel = intel;
    return *this;
}

Equip_Builder Equip_Builder::setInt_mod(unsigned int int_mod) {
    this->int_mod = int_mod;
    return *this;
}

Equip_Builder Equip_Builder::setSpeed(int speed) {
    this->speed = speed;
    return *this;
}

Equip_Builder Equip_Builder::setSpeed_mod(unsigned int speed_mod) {
    this->speed_mod = speed_mod;
    return *this;
}

Equip_Builder Equip_Builder::setStr(int str) {
    this->str = str;
    return *this;
}

Equip_Builder Equip_Builder::setStr_mod(unsigned int str_mod) {
    this->str_mod = str_mod;
    return *this;
}
