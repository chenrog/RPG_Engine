//
// Created by Andrew Alcala on 11/8/2017...
//

#ifndef CS3520_2017FA_PROJ_AENTITY_H
#define CS3520_2017FA_PROJ_AENTITY_H

#include "../World/Posn.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * Class representing an Entity.
 */
class IEntity {
public:
    // TODO: make uninstantiable
    IEntity();

    virtual ~IEntity();

    virtual const string & getName() const;

    virtual Posn getPosition();

    virtual void setPosition(Posn posn);

    virtual bool is_item();

    virtual bool isVisible();

    virtual void enableVisibility();

    virtual void disableVisibility();

protected:
    // The entity properties.
    string name;
    Posn position;
    bool visible;
    bool item;
};


#endif //CS3520_2017FA_PROJ_AENTITY_H
