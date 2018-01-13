#include <iostream>

// 1a)
void inputAndPrintInteger(){
    int x;
    std::cout << "Type in an integer: ";
    std::cin >> x;
    std::cout  << "You typed in: " << x << std::endl;
}

// 1b)
int inputInteger(){
    int x;
    std::cout << "Type in an integer: ";
    std::cin >> x;
    return x;
}

// 1c)
void inputIntegersAndPrintSum(){
    int x, y;
    x = inputInteger();
    y = inputInteger();
    std::cout << "The sum of your numbers are: " << x + y << std::endl;
}

/*
 1d)
 Jeg brukte inputInteger, fordi den returnerer en verdi.
 */

// 1e)
bool isOdd(int x){
    if(x%2 == 0){
        return false;
    }
    return true;
}

void printHumanReadableTime(int sec){
    int hours, minutes;
    hours = static_cast<int>((sec - sec%3600)/3600);
    sec -= hours * 3600;
    minutes = static_cast<int>((sec - sec%60)/60);
    sec -= minutes * 60;
    
    std::cout << hours << (hours == 1 ? " hour, ":" hours, ")
            << minutes << (minutes==1 ? " minute, ":" minutes ")
            << sec << (sec==1 ? " second.":" seconds")
            << std::endl;
}

/*
int main(int argc, char** argv){
    inputAndPrintInteger();
    
    int x = inputInteger();
    std::cout << "Your integer: " << x << std::endl;
    
    inputIntegersAndPrintSum();
    
    for(int i = 0;i < 20; i++){
        std::cout << i << " " << isOdd(i) << std::endl;
    }

    printHumanReadableTime(10000);  
}
*/