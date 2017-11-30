//
// Created by Andrew Alcala on 11/9/2017.
//

#include "MapCell.h"

MapCell::MapCell(Point position, bool walkable) {
    this->position = position;
    this->c_entity;
    this->walkable = walkable;
}

MapCell::MapCell(Point position, IEntity c_entity, bool walkable) {
    this->position = position;
    this->c_entity = c_entity;
    this->walkable = walkable;
}

Point MapCell::getPosition() {
    return position;
}

IEntity MapCell::getEntity() {
    return c_entity;
}

void MapCell::setEntity(const IEntity &entity) {
    c_entity = entity;
}

bool MapCell::isWalkable() {
    return walkable;
}

void MapCell::setWalkability(bool new_walkable) {
    walkable = new_walkable;
}

void MapCell::setRandomEncounters(bool encounter) {
    randomEncounterable = encounter;
}

// some function that controls how this cell is displayed, will be based on whether or not this Cell is "inhabited"
void MapCell::draw() {
    //this is where the color, shape, etc of however we want to display a cell
    // this function will also call draw on the item, if this is the place where we want to draw the sprite of the occupant
}


bool MapCell::isRandomEncounterable() {
    return randomEncounterable;
}
