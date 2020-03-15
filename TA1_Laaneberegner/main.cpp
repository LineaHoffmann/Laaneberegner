#include <iostream>
#include <ostream>
#include "Loan.h"
#include <string>

using namespace std;

int main()
{
    // Variables for input/output
    int setYears = 0;
    std::cin >> setYears;
    std::cout << "Velkommen til laaneberegneren " << std:: endl;
    Loan l2;
    std::cout << "Sæt venligst beløb på lånet, indsæt ikke komma i tallet: ";
    std::cin >> setYears;
    std:: cout << " Sæt hvor mange år de ønsker at lånet skal løbe over: " << std::endl;

    std::cin >> setYears;


    Loan l1(1000000, 30, 4, 3);
    l1.getInterestRate();
    std::cout << "total payment: " << static_cast<long>(l1.totalPayment()) << " Total Interest: " << l1.totalInterest() << std::endl;

    l1.outputPeriodicalPayments(std::cout);





    return 0;
}
