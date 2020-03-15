#include <iostream>
#include <ostream>
#include "Loan.h"
#include <string>

int main()
{
    // Temporary input variable
    std::string input;

    // Outputs a welcome message to the user
    std::cout << "Velkommen til laaneberegneren " << std:: endl;
    // Initilize an object, l2 with default contructor
    Loan l2;

    // Outputs message to user, takes input converts input string to double
    // and using setter to set membervariable on object l2.
    std::cout << "Sæt venligst beløb på lånet, indsæt ikke komma i tallet: ";
    std::cin >> input;
    l2.setDebt(std::stod(input));

    // Outputs message to user, takes input converts input string to int
    // and using setter to set membervariable on object l2.
    std:: cout << "Sæt hvor mange år de ønsker at lånet skal løbe over: ";
    std::cin >> input;
    l2.setYears(std::stoi(input));

    // Outputs message to user, takes input converts input string to int
    // and using setter to set membervariable on object l2.
    std::cout << "Sæt hvor mange terminer de ønsker om året: ";
    std::cin >> input;
    l2.setPaymentsPerYear(std::stoi(input));

    // Outputs message to user, takes input converts input string to double
    // and using setter to set membervariable on object l2.
    std::cout << "Sæt den ønskede rente : " << std::endl;
    std::cin >> input;
    l2.setInterestRate(std::stod(input));

    // Calculates the amount the loaner, l2, have to pay per periode.
    l2.calcPeriodicFee();

    //Outputs the interest rate
    std::cout << "Lånerenten er: " << input << "%" << " Samlet betaling: "<< static_cast<long>(l2.totalPayment()) <<  "Samlet rentegebyr:  " << std::fixed << l2.totalInterest() << std::endl;

    //Outputs the Periodical Payments
    l2.outputPeriodicalPayments(std::cout);

    //test stuff
    Loan l1(1000000, 30, 4, 3);
    l1.getInterestRate();
    std::cout << "total payment: " << static_cast<long>(l1.totalPayment()) << " Total Interest: " << l1.totalInterest() << std::endl;
    l1.outputPeriodicalPayments(std::cout);

    return 0;
}
