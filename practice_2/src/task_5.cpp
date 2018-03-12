#include <iostream>
#include "task_1.hpp"

void calculateLoanPayments(){
    int loan, interest, years;
    std::cout << "Enter your desired loan" << std::endl;
    loan = inputInteger();
    std::cout << "Enter your desired interest" << std::endl;
    interest = inputInteger();
    std::cout << "Enter the number of years you will use to pay back" << std::endl;
    years = inputInteger();    
    std::cout << "Year:\tPayment:\tRemainding loan:\t" << std::endl;
    float remainding_loan = loan, payment;
    for(int i = 1; i <= years; i++){
        payment = loan/years + (interest/100)*remainding_loan;
        remainding_loan -= loan/years;
        std::cout << i << "\t" << payment << "\t\t" <<remainding_loan << std::endl;
    }
    
}
