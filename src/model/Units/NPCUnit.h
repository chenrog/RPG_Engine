#ifndef CS3520_2017FA_PROJ_NPCUNIT_H
#define CS3520_2017FA_PROJ_NPCUNIT_H

#include "AUnit.h"
#include "NPCUnitType.h"
#include "../Item/Item.h"

class NPCUnit : public AUnit {
public:
    /**
     * A constructor for an NPC
     * @param type
     * @param dialogue
     */
    NPCUnit(NPCUnitType_t type, Point point, string name, string dialogue);

    /**
     * A constructor for an NPC of type VENDOR throws an assert error if type is not VENDOR
     * @param type
     * @param dialogue
     */
    NPCUnit(NPCUnitType_t type, Point point, string name, string dialogue, Item items[]);

    ~NPCUnit();

    inline string getDialogue() {return this->dialogue;}

    inline NPCUnitType_t getNPCUnitType() {return this->type;}

    inline Item getItem(int i) {return this->items[i];}

    void addItems(Item item[]);

private:
    NPCUnitType_t type;
    string dialogue;
    Item * items;
};


#endif //CS3520_2017FA_PROJ_NPCUNIT_H
