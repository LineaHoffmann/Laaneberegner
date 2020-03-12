#include <Loan.h>


int Loan::getYears() const
{
    return mYears;

}

void Loan::setYears(int years)
{

}

int Loan::getPaymentsPerYear() const
{

}

void Loan::setPaymentsPerYear(int paymentsPerYear)
{

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
    mInterestRate = rate;
}
