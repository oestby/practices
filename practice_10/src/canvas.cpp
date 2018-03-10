#include "canvas.hpp"

void Canvas::addShape(Shape* shape) {
    shapes.push_back(shape);
}

void Canvas::rasterizeTo(Image& img) {
    for (Shape* obj: shapes) {
        obj->draw(img);
    }
}