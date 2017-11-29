/* The Point class Implementation file (Point.cpp)
 * SOURCE: https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp6_Inheritance.html*/
// Modified to only accept positive points.
#include "Point.h"
#include <iostream>

using namespace std;

// Constructor - The default values are specified in the declaration
Point::Point(unsigned int x, unsigned int y) : x(x), y(y) {}

// Getters
unsigned int Point::getX() const { return x; }

unsigned int Point::getY() const { return y; }

// Setters
void Point::setX(unsigned int x) { this->x = x; }

void Point::setY(unsigned int y) { this->y = y; }

// Public Functions
void Point::setXY(unsigned int x, unsigned int y) {
    this->x = x;
    this->y = y;
}

void Point::print() const {
    cout << "Point @ (" << x << "," << y << ")";
}