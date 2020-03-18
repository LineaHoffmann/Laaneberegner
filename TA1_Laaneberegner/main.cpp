#include <iostream>
#include <iomanip>
#include <ostream>
#include <cmath>
#include "Loan.h"
#include <string>

double rounding(double in);

int main()
{
    // Input variable
    std::string input;

    //initializin static variable values of built-in array and added sums of values for the 5 types of loan
    //Array to hold values for different types of loans from https://www.totalkredit.dk/siteassets/dokumenter/privat/prisblad/prisblad.pdf
    double loanDetailArr[5]{2.0, 2.6, 2.7, 1.45, 1.7};

    // Outputs a welcome message to the user
    std::cout << "Velkommen til laaneberegneren " << std:: endl;
    // Initilize an object, l2 with default contructor
    Loan l2;

    // Outputs message to user, takes input converts input string to double
    // and using setter to set membervariable on object l2.
    std::cout << "Saet venligst beloeb paa laanet, indsaet ikke komma i tallet: ";
    std::cin >> input;
    l2.setDebt(std::stod(input));

    // Outputs message to user, takes input converts input string to int
    // and using setter to set membervariable on object l2.
    std:: cout << "Saet hvor mange aar de oensker at laanet skal loebe over: ";
    std::cin >> input;
    l2.setYears(std::stoi(input));

    // Outputs message to user, takes input converts input string to int
    // and using setter to set membervariable on object l2.
    std::cout << "Saet hvor mange terminer de oensker om aaret: ";
    std::cin >> input;
    l2.setPaymentsPerYear(std::stoi(input));

    // Outputs message to user, takes input converts input string to double
    // and using setter to set membervariable on object l2.
    std::cout << "Saet den oenskede rente : ";
    std::cin >> input;
    l2.setInterestRate(std::stod(input));

    // Calculates the amount the loaner, l2, have to pay per periode.
    l2.calcPeriodicFee();

    //Outputs the interest rate
    std::cout << std::fixed << std::setprecision(2)
              << "Laanerenten er: " << input << "% \n"
              << " Samlet betaling: "<< rounding(l2.totalPayment())  << "\n"
              <<  " Samlet rentegebyr:  " << l2.totalInterest() << std::endl;

    // Outputs the interest with tax deduction
    std::cout << "Samlet fradrag: " <<l2.totalInterestTaxDeducted(30.6) << std::endl;
    //Outputs the Periodical Payments
    l2.outputPeriodicalPayments(std::cout);

    //Outputs loan details for all loan types
    std::cout << "Beregner for andre laanetyper med hhv. 2% rente, 2,6% rente, 2,7% rente, 1,45% rente, 1.7% rente" << std::endl;
    l2.calcAllLoan(loanDetailArr,_countof(loanDetailArr));

    //test stuff
//    Loan l1(1000000, 30, 4, 3);
//    l1.getInterestRate();
//    std::cout << "total payment: " << static_cast<long>(l1.totalPayment()) << " Total Interest: " << l1.totalInterest() << std::endl;
//    l1.outputPeriodicalPayments(std::cout);

//    l1.calcAllLoan(loanDetailArr,_countof(loanDetailArr));

    std::cout << lrint(5.5) << " " << lrint(6.5) << std::endl;

    return 0;
}

double rounding(double in)
{
    return std::lrint(100 * in)/100;
}
