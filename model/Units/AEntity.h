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
    //TODO: I want to define all the func bodies in the cpp, but then how do we keep AEntity abstract???

    virtual const string & getName() const = 0;

    virtual Point getPosition() = 0;

    virtual bool isVisible() = 0;

    virtual void enableVisibility() = 0;

    virtual void disableVisibility() = 0;

protected:
    // The entity properties.
    string name;
    Point position;
    bool visible;
};


#endif //CS3520_2017FA_PROJ_AENTITY_H
