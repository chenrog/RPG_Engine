#include "Item.h"

Item::Item() {}

Item::Item(const Item &item);

string Item::getDescription() {
    return description;
}