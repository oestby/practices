#ifndef LINE_HPP
#define LINE_HPP

#include "shape.hpp"

//A simple struct for organizing points.
struct Point {
    int x, y;
    Point(int x, int y): x(x), y(y) {}
};

class Line: public Shape {
public:
    Line(const Point& start, const Point& end, const Color& color);
    virtual void draw(Image& img) override;
private:
    Point start, end;
};


#endif
