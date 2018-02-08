#include "GameObjects.h"

#include "cannonball.hpp"
#include <cmath>

// implement all (member) functions in this file

bool hitTarget(const Cannonball& c, const Target& t) {
    return c.shape.getGlobalBounds().intersects(t.shape.getGlobalBounds());
}


bool Cannonball::hasLanded() const {
    return getPosY() + size < 0;
}

double Cannonball::getAirTime() const {
    return SPEED_FACTOR*clock.getElapsedTime().asSeconds();
}

double Cannon::getTipX() const {
    return length*cos(degToRad(theta));
}

double Cannon::getTipY() const {
    return length*sin(degToRad(theta));
}

Target::Target(double size, double position):
size(size), position(position)
{
    this->shape = sf::RectangleShape(sf::Vector2f(this->size, this->size));
    this->shape.setFillColor(sf::Color::Red);
    this->shape.setPosition(this->position, this->position);
}

void
Target::update()
{

}

void
Target::draw(sf::RenderWindow& window)
{
    window.draw(this->shape);
}


Cannon::Cannon()
{
    this->shape.setOrigin(this->width/2, 0);
    this->shape.setPosition(0,0);
}

void
Cannon::update()
{
    this->shape.setRotation(this->theta);
}

void
Cannon::draw(sf::RenderWindow& window)
{
    window.draw(this->shape);
}

