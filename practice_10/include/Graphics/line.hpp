#ifndef LINE_HPP
#define LINE_HPP

#include "shape.hpp"

class Shape;

class Line: public Shape {
public:
    Line(const Point& start, const Point& end, const Color& color);
    virtual void draw(Image& img);
private:
    Point start, end;
};


#endif
