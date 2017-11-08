#ifndef CS3520_2017FA_PROJ_POINT_H
#define CS3520_2017FA_PROJ_POINT_H

/* The Point class Header file (Point.h)
 * SOURCE: https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp6_Inheritance.html*/

class Point {
private:
    int x, y;  // Private data members

public:
    Point(int x = 0, int y = 0); // Constructor with default arguments
    int getX() const;  // Getter
    void setX(int x);  // Setter
    int getY() const;

    void setY(int y);

    void setXY(int x, int y);

    void print() const;
};

#endif //CS3520_2017FA_PROJ_POINT_H
