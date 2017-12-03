#include "Item.h"
Item::Item() {
    this->name = "undefined name";
    this->description = "undefined description";
}

Item::Item(string name, string desc) {
    this->name = name;
    this->description = desc;
}

string Item::getDescription() {
    return description;
}