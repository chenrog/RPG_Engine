#include "Consumable.h"

#include <utility>

Consumable::Consumable(string name, int potency, consumable_type_t type, string description) {
    this->name = std::move(name);
    this->potency = potency;
    this->type = type;
    this->description = std::move(description);
}

Consumable::Consumable(string name, int potency, consumable_type_t type, string description, Point point) {
    this->name = std::move(name);
    this->potency = potency;
    this->type = type;
    this->description = std::move(description);
    this->position = point;
}

Consumable::Consumable(const Consumable &item) {
    this->name = item.name;
    this->potency = item.potency;
    this->type = item.type;
    this->description = item.description;
    this->position = item.position;
}
