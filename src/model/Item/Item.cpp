#include "Item.h"

Item::Item(string name, string desc) {
    this->name = name;
    this->description = desc;
}

string Item::getDescription() {
    return description;
}