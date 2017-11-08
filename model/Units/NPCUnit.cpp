#include "NPCUnit.h"
#include <cassert>

NPCUnit::NPCUnit(NPCUnitType_t type, string name, string dialogue) {

    this->type = type;
    this->dialogue = dialogue;
}

NPCUnit::NPCUnit(NPCUnitType_t type, string name, string dialogue, Item[] items) {
    assert(type == VENDOR);
    this->type = type;
    this->dialogue = dialogue;
    this->items = items;
}

NPCUnit::~NPCUnit() {
    delete this->items;
}

