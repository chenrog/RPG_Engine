//
// Created by Roger Chen on 11/6/17.
//

#include "Equipment.h"

using namespace std;

Equipment::Equipment(string name, Posn position, bool visible, equip_type_t type, signed int v, unsigned int vm,
                     signed int i, unsigned int im, signed int sp, unsigned int spm,
                     signed int st, unsigned int stm, string description) :
        level(0), type(type), vit(v), vit_mod(vm), intel(i), int_mod(im), speed(sp), speed_mod(spm), str(st), str_mod(stm) {

        this->name = std::move(name);
        this->position = position;
        this->visible = visible;
        this->description = std::move(description);
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

// BUILDER FROM HERE ON OUT

static const bool         DEFAULT_VIS = false;
// vitality stats by this equipment
static const signed int   DEFAULT_VIT = 0;
static const unsigned int DEFAULT_VMOD = 0;
// intelligence stats by this equipment
static const signed int   DEFAULT_INT = 0;
static const unsigned int DEFAULT_IMOD = 0;
// dex stats by this equipment
static const signed int   DEFAULT_DEX = 0;
static const unsigned int DEFAULT_DMOD = 0;
// strength stats by this equipment
static const signed int   DEFAULT_STR = 0;
static const unsigned int DEFAULT_SMOD = 0;
static const string       DEFAULT_DESC = "Equipment.";

Equip_Builder::Equip_Builder(string name, equip_type_t type) : name(std::move(name)), type(type),
visible(DEFAULT_VIS), vit(DEFAULT_VIT), vit_mod(DEFAULT_VMOD), intel(DEFAULT_INT), int_mod(DEFAULT_IMOD),
dex(DEFAULT_DEX), dex_mod(DEFAULT_DMOD), str(DEFAULT_STR), str_mod(DEFAULT_SMOD), desc(DEFAULT_DESC) { }

// this builds a new Equipment with the stats of this equipment
Equipment * Equip_Builder::build() {
    auto equipment = new Equipment(name, position, visible, type, vit, vit_mod, intel, int_mod, dex, dex_mod, str, str_mod, desc);
    return equipment;
}

Equip_Builder Equip_Builder::setPosition(const Posn &position) {
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

Equip_Builder Equip_Builder::setDex(int dex) {
    this->dex = dex;
    return *this;
}

Equip_Builder Equip_Builder::setDex_mod(unsigned int dex_mod) {
    this->dex_mod = dex_mod;
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

Equip_Builder Equip_Builder::setDesc(string desc) {
    //delete this->desc; //TODO: Not if needed causing build error
    this->desc = std::move(desc);
}
