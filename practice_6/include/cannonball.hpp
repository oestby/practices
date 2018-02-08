#ifndef CANNONBALL_HPP
#define CANNONBALL_HPP

//Returns the acceleration in the y direction
double acclY();

// Returns the velocity in the y direction
double velY(double initVelocity, double time);

// Returns the position in the x direction
double posX(double initPosition, double initVelocity, double time);

// Returns the position in the y direction
double posY(double initPosition, double initVelocity, double time);

// Prints pretty time
void printTime(int seconds);

// Returns the total flighttime
double flightTime(double initVelocity);

// Gets a user input and stores it in pointers
void getUserInput(double* theta, double* absVelocity);

// Converts degrees to radians
double degToRad(double deg);

// Returns the velocity in the x direction based on theta and absVel 
double getVelocityX(double theta, double absVelocity);

// Returns the velocity in the y direction
double getVelocityY(double theta, double absVelocity);

// Makes the two pointers equal to the x and y velocity
void getVelocityVector(double theta, double absVelocity,
        double* velocityX, double* velocityY);

// Returns the distance traveled
double getDistanceTraveled(double velocityX, double velocityY);

// Returns the distance to the target
double targetPractice(double distanceToTarget, double velocityX,
        double velocityY);

void playTargetPractice();

#endif

