#ifndef CANVAS_HPP
#define CANVAS_HPP

#include "graphics.hpp"
#include <vector>

class Canvas {
public:
    void addShape(Shape* shape);
    void rasterizeTo(Image& img);

private:
    std::vector<Shape*> shapes;
};

#endif
