#include "Graphics/line.hpp"
#include <algorithm>
#include <iostream>

Line::Line(const Point& start, const Point& end, const Color& color):
Shape(color), start(start.x, start.y), end(end.x, end.y)
{
    //Swaps start and end point 
    if (start.x > end.x) {
        Point temp = this->start;
        this->start = this->end;
        this->end = temp;
    }
}

void Line::draw(Image& img) {
    if (static_cast<float>((end.y - start.y))/(end.x - start.x) < 1) {
        int y = 0;
        for (int x = start.x; x < end.x; x++) {
            y = static_cast<float>((end.y - start.y))/(end.x - start.x) * (x - start.x) + start.y;
            img.setPixelColor(x, y, getColor());
        }
    }else
    {
        int x = 0;
        for (int y = start.y; y < end.y; y++) {
            x = static_cast<float>(end.x - start.x)/(end.y - start.y) * (y - start.y) + start.x;
            img.setPixelColor(x, y, getColor());
        }
    }

}
