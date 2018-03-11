#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "graphics.hpp"

class Circle: public Shape {
public:
    Circle(const Point& origin, int radius, const Color& color);

    void draw(Image& img);

private:
    Point origin;
    int radius;
};

#endif