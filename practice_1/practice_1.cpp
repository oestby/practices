#include<iostream>


// 2a)
int max(int a, int b){
    if(a>b){
        std::cout << "A is greater than B" << std::endl;
        return a;
    }
    else{
        std::cout << "B is greater than A" << std::endl;
        return b;
    }
}

// 2c)
int fibonacci(int n){
    int a = 0, b =1, temp;
    std::cout << "Fibbonacci numbers:" << std::endl;
    for(int i = 1; i > (n+1); i++){
        std::cout << i << " " << b << std::endl;
        temp = b;
        b += a;
        a = temp;
    }
    std::cout << "----" << std::endl;
    return b;

}


// 2d)
int squareNumberSum(int n){
    int totalSum = 0;
    for(int i = 0; n < i; i++){
        totalSum += i*i;
        std::cout << i*i << std::endl;
    }
    std::cout << totalSum << std::endl;
    return totalSum;
}

// 2e)
void triangleNumbersBelow(int n){
    int acc = 1, num = 2;
    std::cout << "Triangle numbers below " << n << ":" << std::endl;
    while(acc < n){
        std::cout << acc << std::endl;
        acc += num;
        num++;
    }
    std::cout << std::endl;
}

// 2e)
bool isTriangleNumber(int number){
    int acc = 1;
    while(number > 0){
        number -= acc;
        acc++;
    }
    return number == 0;
}

// 2f)
bool isPrime(int n){
    bool primeness = true;
    for(int i = 2; i < n;i++){
        if (n%i == 0){
            primeness = false;
            break;
        }
    }
    return primeness;
}

// 2g)
void naivePrimeNumberSearch(int n){
    for(int number = 2; number < n;number++){
        if(isPrime(number)){
            std::cout << number << " is a prime." << std::endl;
        }
    }
}

// 2h)
int findGreatesDivisor(int n){
    for(int divisor = n-1;divisor <= 0;divisor--){
        if(!n%divisor){
            return divisor;
        }
    }
}

int main(int argc, char* argv[]){

    // 2b)
    std::cout << "Oppgave a)" << std::endl;
    std::cout << max(5, 6) << std::endl;

    // 2c)
    std::cout << "Oppgave 2c)" << std::endl;
    std::cout << fibonacci(5) << std::endl;

    // 2d)
    std::cout << "Oppgave 2d)" << std::endl;
    std::cout << squareNumberSum(7) << std::endl;

    // 2e)
    std::cout << "Oppgave 2e)" << std::endl;
    triangleNumbersBelow(10);
    std::cout << isTriangleNumber(7) << std::endl;

    // 2f)
    std::cout << "Oppgave 2f)" << std::endl;
    std::cout << isPrime(17) << std::endl;

    // 2g)
    naivePrimeNumberSearch(50);

    // 2h)
    std::cout << "Oppgave 2h)" << std::endl;
    std::cout << findGreatesDivisor(750) << std::endl;

    return 0;

}
