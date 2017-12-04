//
// Created by Andrew Alcala on 12/3/2017.
//

help

#ifndef CS3520_2017FA_PROJ_POSN_H
#define CS3520_2017FA_PROJ_POSN_H

#include "../src/model/World/Posn.h"

class PosnTest {
public:

    void testPosn1Get() {
        Posn *p1 = new Posn(0, 0);
        TS_ASSERT_EQUALS(p1->getX(), 0);
        TS_ASSERT_EQUALS(p1->getY(), 0);
        delete p1;
    }

    void testPosn2Get() {
        Posn *p1 = new Posn(3, 5);
        TS_ASSERT_EQUALS(p1->getX(), 3);
        TS_ASSERT_EQUALS(p1->getY(), 5);
        delete p1;
    }

    void testPosn3Set() {
        Posn *p1 = new Posn(0, 0);
        TS_ASSERT_EQUALS(p1->getX(), 0);
        TS_ASSERT_EQUALS(p1->getY(), 0);
        p1->setX(10);
        TS_ASSERT_EQUALS(p1->getX(), 10);
        TS_ASSERT_EQUALS(p1->getY(), 0);
        p1->setY(20);
        TS_ASSERT_EQUALS(p1->getX(), 10);
        TS_ASSERT_EQUALS(p1->getY(), 20);
        delete p1;
    }

    void testPosn4SetBoth() {
        Posn *p1 = new Posn(0, 0);
        TS_ASSERT_EQUALS(p1->getX(), 0);
        TS_ASSERT_EQUALS(p1->getY(), 0);
        p1->setXY(20, 149);
        TS_ASSERT_EQUALS(p1->getX(), 20);
        TS_ASSERT_EQUALS(p1->getY(), 149);
    }


};

#endif //CS3520_2017FA_PROJ_POSN_H
