#include "Item.h"
Item::Item() {
    this->name = "undefined name";
    this->description = "undefined description";
    this->item = true;
}

Item::Item(string name, string desc) {
    this->name = name;
    this->description = desc;
    this->item = true;
}


string Item::getDescription() {
    return description;
}