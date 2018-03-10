#include "Image.h"

/*****************************************************
 * You _should_ change the functions in this file.   *
 * The following functions are provided so that      *
 * the code will compile, note however that the      *
 * program will not run before you have implemented  *
 * all the functions in this file.                   *
 *****************************************************/

Image::Image( int width, int height ):
width(width), height(height)
{
    data = new Pixel[width * height];
}

Image::~Image()  {
    delete[] data;
    data = nullptr;
}

int Image::getWidth() const {
    return width;
}
int Image::getHeight() const  {
    return height;
}

const Pixel * Image::getScanLine(int line) const  {
    if (line < height) {
        return &data[line * width];
    }
    else { 
        return nullptr;
    }
}
Pixel * Image::getScanLine(int line) {
    if (line < height) {
       return &data[line * width];
    } 
    else{
        return nullptr;
    }
}

Color Image::getPixelColor( int x, int y ) const {
    Color temp = data[y * width + x];
    return temp;
}

void Image::setPixelColor( int x, int y, const Color &color ) {
    if (y * width + x < width*height) {
        data[y * width + x] = color;
    }
}

void Image::fill( const Color &color ) {
    for (int i = 0; i < (width * height); i++) {
        data[i] = color;
    }
}
