#include <Loan.h>
#include <iostream>
#include <math.h>


Loan::Loan(double debt, int years, int paymentsPerYear, double interestRate)
{
    setDebt(debt);
    setYears(years);
    setPaymentsPerYear(paymentsPerYear);
    setInterestRate(interestRate);
}

int Loan::getYears() const
{
    return mYears;

}

void Loan::setYears(int years)
{
    mYears = years;

}

int Loan::getPaymentsPerYear() const
{
    return mPaymentsPerYear;

}

void Loan::setPaymentsPerYear(int paymentsPerYear)
{
    mPaymentsPerYear = paymentsPerYear;

}

double Loan::getDebt() const
{
    return mDebt;
}

void Loan::setDebt(double debt)
{
    mDebt = debt;
}

double Loan::getInterestRate() const
{
    return mInterestRate;
}

void Loan::setInterestRate(double rate)
{
   mInterestRate = rate/mPaymentsPerYear;
   std::cout << mInterestRate << std::endl;

}

double Loan::totalInterest() const
{
    return totalPayment() - getDebt();
}

double Loan::totalPayment() const
{
         double y = mDebt * (mInterestRate/100)/(1 - (1/pow((1 + (mInterestRate/100)), static_cast<long double>(mYears * mPaymentsPerYear))));

    return y * (mYears * mPaymentsPerYear);
}
