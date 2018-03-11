#include "Graphics/circle.hpp"
#include <cmath>
#include <iostream>

Circle::Circle(const Point& origin, int radius, const Color& color):
Shape(color), origin(origin), radius(radius)
{
    //Empty
}

void Circle::draw(Image& img) {
    for (int x = origin.x - radius; x <= origin.x + radius; x++) {
        for (int y = origin.y - radius; y <= origin.y + radius; y++) {
            if (fabs(pow(x - origin.x, 2) + pow(y - origin.y,2) -  pow(radius,2)) <= radius) {
                img.setPixelColor(x, y, getColor());
            }
        }
    }

}
