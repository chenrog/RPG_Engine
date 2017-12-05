#ifndef CS3520_2017FA_PROJ_POINT_H
#define CS3520_2017FA_PROJ_POINT_H

/* The Posn class Header file (Posn.h)
 * SOURCE: https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp6_Inheritance.html*/

class Posn {
private:
    unsigned int x, y;  // Private data members

public:
    Posn(unsigned int x = 0, unsigned int y = 0); // Constructor with default arguments
    unsigned int getX() const;  // Getter
    void setX(unsigned int x);  // Setter
    unsigned int getY() const;

    void setY(unsigned int y);

    void setXY(unsigned int x, unsigned int y);

    void print() const;
};

#endif //CS3520_2017FA_PROJ_POINT_H
