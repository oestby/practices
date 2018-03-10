#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "Image.h"

//Abstact base class for many drawable objects.

class Shape {
public:
    Shape(const Color& color): color(color) { }
    Color getColor(void) const { return color; }

    //For drawing to an image.
    virtual void draw(Image& img);
private:
    Color color;
};

#endif
