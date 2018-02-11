#include "cannonball.hpp"
#include "utilities.hpp"

#include <memory>
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
    std::cout << "Enter a velocity: ";
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

double getDistanceTraveled(double velocityX, double velocityY){
    double time = flightTime(velocityY);
    return posX(0, velocityX, time);
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY){
    return distanceToTarget - getDistanceTraveled(velocityX, velocityY);
}

void playTargetPractice(){
    double *theta_p = new double;
    double *absVelocity_p = new double;
    double *velocityX_p = new double;
    double *velocityY_p = new double;
    int tries = 10;
    bool hit = false;
    double error, distance = randomWithLimits(100, 1000);
    std::cout << "The target is set up between 100 and 1000 meters."
    << std::endl << "You have 10 tries!" << std::endl;
    
    while(tries && !hit){
        getUserInput(theta_p, absVelocity_p);
        getVelocityVector(degToRad(*theta_p), *absVelocity_p, velocityX_p, velocityY_p);
        error = targetPractice(distance, *velocityX_p, *velocityY_p);
        std::cout << "You were " << error << "m away form the target." << std::endl;
        if(abs(error) < 5.0){
            std::cout << "That means you hit the target!" << std::endl;
            hit = true;
        }
        else if(tries == 1){
            std::cout << "Sorry, you didn't make it, try again later..." << std::endl;
        }
        else{
            std::cout << "Too bad, try again!" << std::endl
            << "You have " << (tries-1) << " tries left." << std::endl;

        }
        tries--;
        std::cout << std::endl;
    }
    delete theta_p;
    delete absVelocity_p;
    delete velocityX_p;
    delete velocityY_p;
}
