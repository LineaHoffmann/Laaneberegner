#include <iostream>
#include <ostream>
#include "Loan.h"

using namespace std;

int main()
{
    // Variables for input/output
    int setYears = 0;
    std::cin >> setYear;
    std::cout << "Velkommen til laaneberegneren " << std:: endl;


    Loan l1(1000000, 30, 4, 3);
    l1.getInterestRate();
    std::cout << "total payment: " << static_cast<long>(l1.totalPayment()) << " Total Interest: " << l1.totalInterest() << std::endl;

    l1.outputPeriodicalPayments(std::cout);





    return 0;
}
