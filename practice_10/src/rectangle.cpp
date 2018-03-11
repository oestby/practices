#include "Graphics/rectangle.hpp"

Rectangle::Rectangle(const Point& left_corner, const Point& right_corner, const Color& color):
Shape(color), l_corner(left_corner), r_corner(right_corner)
{
    //empty <3
}

void Rectangle::draw(Image& img) {
    for (int x = l_corner.x; x < r_corner.x; x++) {
        img.setPixelColor(x, l_corner.y, getColor());
        img.setPixelColor(x, r_corner.y, getColor());
    }
    for (int y = l_corner.y; y < r_corner.y; y++) {
        img.setPixelColor(l_corner.x, y, getColor());
        img.setPixelColor(r_corner.x, y, getColor());
    }
}
