#include "IEntity.h"

IEntity::IEntity() {

}

IEntity::~IEntity() {

}

const string &IEntity::getName() const {
    return name;
}

Point IEntity::getPosition() {
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
