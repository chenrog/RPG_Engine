//
// Created by whyar on 11/6/2017.
//

#ifndef CS3520_2017FA_PROJ_ITEM_H
#define CS3520_2017FA_PROJ_ITEM_H

#include "../Units/IEntity.h"

class Item : public IEntity {
public:
    Item(string name, string desc);
    string getDescription();

protected:
    string description;
};

#endif //CS3520_2017FA_PROJ_ITEM_H
