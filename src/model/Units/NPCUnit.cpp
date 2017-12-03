#include "NPCUnit.h"
#include <cassert>

NPCUnit::NPCUnit(NPCUnitType_t type, Posn point, string name, string dialogue) {
    this->position = point;
    this->type = type;
    this->visible = true;
    this->dialogue = dialogue;
}

NPCUnit::NPCUnit(NPCUnitType_t type, Posn point, string name, string dialogue, Item items[]) {
    assert(type == VENDOR);
    this->position = point;
    this->visible = true;
    this->type = type;
    this->dialogue = dialogue;
    this->items = items;
}

void NPCUnit::addItems(Item *item) {
    this->items = item;
}

NPCUnit::~NPCUnit() {
    delete[] this->items;
}

