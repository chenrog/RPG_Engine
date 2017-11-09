//
// Created by whyar on 11/8/2017.
//

#ifndef CS3520_2017FA_PROJ_CONSUMABLE_H
#define CS3520_2017FA_PROJ_CONSUMABLE_H

#include "Item.h"
#include "Consumable_Type_t.h"

class Consumable : public Item, public AEntity {
public:
    Consumable(string name, int potency, consumable_type_t type, string description);
    Consumable(string name, int potency, consumable_type_t type, string description, Point point);
    Consumable(const Consumable &item);

    int get_potency();
    consumable_type_t get_type();
    string get_description();

private:
    int potency;
    consumable_type_t type;
};

#endif //CS3520_2017FA_PROJ_CONSUMABLE_H
