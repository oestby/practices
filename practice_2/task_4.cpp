#include <iostream>
#include <cmath>

// 4a)
double discriminant(double a, double b, double c){
    return (pow(b, 2) - 4 * a * c);
}

// 4b)
void printRealRoots(double a, double b, double c){
    if(discriminant(a, b, c) == 0){
    std::cout << "The equation has one real root: " << (-b/(2*a)) << std::endl;
    }
    else if(discriminant(a, b, c) < 0){
        std::cout << "No real roots!" << std::endl;
    }
    else{
        std::cout << "The equation has the two roots: " << (-b + discriminant(a, b, c))/(2*a) << " and "
        << (-b - discriminant(a, b, c))/2*a << std::endl; 
    }
}

// 4c)
void solveQuadraticEquation(){
    double a, b, c;
    std::cout << "Type in a, b and c from ax² + bx + c to solve the equation." << std::endl
    << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    std::cout << "c = ";
    std::cin >> c;
    printRealRoots(a, b, c);
}
/*
int main(int argc, char** argv){
    solveQuadraticEquation();
}
*/