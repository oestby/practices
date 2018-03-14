#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "Image.h"

//A simple struct for organizing points.
struct Point {
    int x, y;
    Point(int x, int y): x(x), y(y) {}
};

//Abstact base class for many drawable objects.
class Shape {
public:
    Shape(const Color& color): 
    color(color)
    {
        //Empty
    }

    Color getColor(void) const { return color; }

    //For drawing to an image.
    virtual void draw(Image& img) = 0;
private:
    Color color;
};

#endif
