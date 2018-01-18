#include "cannonball.hpp"
#include <iostream>
#include <math.h>

constexpr double PI = 3.14159265;

double acclY(){
    return -9.81;
}

double velY(double initVelocity, double time){
    return initVelocity + acclY() * time;
}

double posX(double initPosition, double initVelocity, double time){
    return initPosition + initVelocity * time;
        // Is this just 0? + (acclX() * time * time)/2;
}

double posY(double initPosition, double initVelocity, double time){
    return initPosition + initVelocity * time + (acclY() * time * time)/2;
}

void printTime(int seconds){
    int h, m;
    while(seconds-3600 >= 0){
        h += 3600;
        seconds -= 3600;
    }
    while(seconds-60 >= 0){
        m += 60;
        seconds -= 60;
    }
    std::cout << h << " hours, " 
        << m << " minutes and " 
        << seconds << " seconds."
        << std::endl;
}

double flightTime(double initVelocity){
    return (-2 * initVelocity)/acclY();
}

void getUserInput(double* theta, double* absVelocity){
    std::cout << "Enter a number of degrees: ";
    std::cin >> *theta;
    std::cout << std::endl << "Enter a velocity: ";
    std::cin >> *absVelocity;
    std::cout << std::endl;
}

double degToRad(double deg){
    return (deg * PI)/180;
}

double getVelocityX(double theta, double absVelocity){
    return absVelocity * cos(degToRad(theta));
}

double getVelocityY(double theta, double absVelocity){
    return absVelocity * sin(degToRad(theta));
}

void getVelocityVector(double theta, double absVelocity,
        double* velocityX, double* velocityY){
    *velocityX = getVelocityX(theta, absVelocity);
    *velocityY = getVelocityY(theta, absVelocity);
}

//TODO: Implement this shit.
double getDistanceTraveled(double velocityX, double velocityY){
    double time = flightTime(velocityY);
    return posX(0, velocityX, time);
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY){
    return distanceToTarget - getDistanceTraveled(velocityX, velocityY);
}

void playTargetPractice(){

}

