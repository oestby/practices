#include "line.hpp"
#include <algorithm>

Line::Line(const Point& start, const Point& end, const Color& color):
start(start), end(end), Shape(color)
{
    //Swaps start and end point 
    if (start.x > end.x) {
        Point temp = this->start;
        this->start = this->end;
        this->end = temp;
    }
}

void Line::draw(Image& img) {
    for (int x = start.x; x < end.x; x++) {
        int f_y = (end.y - start.y)/(end.x - start.x) * (x - start.x) + start.y;
        img.setPixelColor(x, f_y, getColor());
    }

}