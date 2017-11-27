//
// Created by Andrew Alcala on 11/9/2017.
//

#ifndef CS3520_2017FA_PROJ_MAPCELL_H
#define CS3520_2017FA_PROJ_MAPCELL_H


#include "Units/AEntity.h"

class MapCell {
public:
    MapCell(Point position, bool walkable);

    MapCell(Point position, AEntity c_entity, bool walkable);

    Point getPosition();

    AEntity getEntity();

    void setEntity(const AEntity& entity);

    bool isWalkable();

    void setWalkability(bool new_walkable);

    bool isRandomEncounterable();

    void setRandomEncounters(bool encounter);

    void draw();


private:
    Point position;
    AEntity c_entity;
    bool walkable;
    bool randomEncounterable;
};


#endif //CS3520_2017FA_PROJ_MAPCELL_H
