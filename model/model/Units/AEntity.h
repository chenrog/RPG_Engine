//
// Created by Andrew Alcala on 11/8/2017...
//

#ifndef CS3520_2017FA_PROJ_AENTITY_H
#define CS3520_2017FA_PROJ_AENTITY_H

#include "../Point.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * Class representing an Entity.
 */
class AEntity {
public:
    // TODO: make uninstantiable
    AEntity();

    virtual ~AEntity();

    virtual const string & getName() const;

    virtual Point getPosition();

    virtual bool isVisible();

    virtual void enableVisibility();

    virtual void disableVisibility();

protected:
    // The entity properties.
    string name;
    Point position;
    bool visible;
};


#endif //CS3520_2017FA_PROJ_AENTITY_H
