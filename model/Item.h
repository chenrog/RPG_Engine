//
// Created by whyar on 11/6/2017.
//

#ifndef CS3520_2017FA_PROJ_ITEM_H
#define CS3520_2017FA_PROJ_ITEM_H

#include "Units/AEntity.h"

class Item : public AEntity {
public:
    Item();
    string getDescription();

protected:
    string description;
};

#endif //CS3520_2017FA_PROJ_ITEM_H
