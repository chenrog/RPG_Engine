#include "IEntity.h"

IEntity::IEntity() {
}

IEntity::~IEntity() {

}

const string &IEntity::getName() const {
    return name;
}

Posn IEntity::getPosition() {
    return position;
}

bool IEntity::isVisible() {
    return visible;
}

void IEntity::enableVisibility() {
    visible = true;
}

void IEntity::disableVisibility() {
    visible = false;
}

void IEntity::setPosition(Posn posn) {
    this->position = posn;
}

bool IEntity::is_item() {
    return item;
}