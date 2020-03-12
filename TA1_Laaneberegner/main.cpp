#include <iostream>
#include "Loan.h"

using namespace std;

int main()
{
    Loan l1(1000000, 30, 4, 3);
    l1.getInterestRate();
    l1.totalPayment();
    return 0;
}
