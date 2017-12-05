#include "NPCUnit.h"
#include <cassert>

NPCUnit::NPCUnit(NPCUnitType_t type, Posn point, string name, string dialogue) {
    this->position = point;
    this->type = type;
    this->visible = true;
    this->name = std::move(name);
    this->dialogue = std::move(dialogue);
}

NPCUnit::NPCUnit(NPCUnitType_t type, Posn point, string name, string dialogue, Item** items) {
    assert(type == VENDOR);
    this->position = point;
    this->visible = true;
    this->type = type;
    this->name = std::move(name);
    this->dialogue = std::move(dialogue);
    this->items = items;
}

NPCUnit::~NPCUnit() {
    delete[] this->items;
}

void NPCUnit::setItems(Item** items) {
    this->items = items;
}

