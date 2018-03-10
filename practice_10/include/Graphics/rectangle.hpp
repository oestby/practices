#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Shape;

class Rectangle: public Shape {
public:
    Rectangle(const Point& left_corner, const Point& right_corner, const Color& color);
    void draw(Image& img);
private:
    Point l_corner, r_corner;
};


#endif
