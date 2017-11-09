//
// Created by Andrew Alcala on 11/9/2017.
//

#include "MapCell.h"

MapCell::MapCell(Point position, AEntity c_entity, bool walkable) {
    this->position = position;
    this->c_entity = c_entity;
    this->walkable = walkable;
}

Point MapCell::getPosition() {
    return position;
}

AEntity MapCell::getEntity() {
    return c_entity;
}

void MapCell::setEntity(const AEntity &entity) {
    c_entity = entity;
}

bool MapCell::isWalkable() {
    return walkable;
}

void MapCell::setWalkability(bool new_walkable) {
    walkable = new_walkable;
}
