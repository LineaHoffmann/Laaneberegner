#include <iostream>
#include "Loan.h"

using namespace std;

int main()
{
    Loan l1(1000000, 30, 4, 3);
    l1.getInterestRate();
    std::cout << "total payment: " << static_cast<long>(l1.totalPayment()) << " Total Interest: " << l1.totalInterest() << std::endl;
    return 0;
}
