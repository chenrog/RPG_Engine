//
// Created by Andrew Alcala on 11/8/2017...
//

#ifndef CS3520_2017FA_PROJ_AENTITY_H
#define CS3520_2017FA_PROJ_AENTITY_H

#include <iostream>
#include "../Point.h"

using namespace std;

/**
 * Class representing an Entity.
 */
class AEntity {
public:
    AEntity();

    virtual ~AEntity();

    virtual Point getPosition() = 0;

    virtual bool isVisible() = 0;

    virtual string getName() = 0;

    virtual void enableVisibility() = 0;

    virtual void disableVisibility() = 0;

protected:
    // The entity properties.
    Point position;
    bool visible;
    string name;
};


#endif //CS3520_2017FA_PROJ_AENTITY_H
