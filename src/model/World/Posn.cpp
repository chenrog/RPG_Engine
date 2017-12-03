/* The Point class Implementation file (Point.cpp)
 * SOURCE: https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp6_Inheritance.html*/
// Modified to only accept positive points.
#include "Posn.h"
#include <iostream>

using namespace std;

// Constructor - The default values are specified in the declaration
Posn::Posn(unsigned int x, unsigned int y) : x(x), y(y) {}

// Getters
unsigned int Posn::getX() const { return x; }

unsigned int Posn::getY() const { return y; }

// Setters
void Posn::setX(unsigned int x) { this->x = x; }

void Posn::setY(unsigned int y) { this->y = y; }

// Public Functions
void Posn::setXY(unsigned int x, unsigned int y) {
    this->x = x;
    this->y = y;
}

void Posn::print() const {
    cout << "Point @ (" << x << "," << y << ")";
}