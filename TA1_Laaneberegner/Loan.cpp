#include <Loan.h>
#include <iostream>
#include <math.h>


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
    mInterestRate = rate;
}

double Loan::totalInterest() const
{

}

double Loan::totalPayment() const
{
    double result{0};
    double remaining = mDebt;
    for ( size_t n = 0; n < static_cast<size_t>(mYears); ++n)
    {
        result += remaining *(1./(1 - pow(1 + static_cast<double>(mInterestRate)/mPaymentsPerYear,-n)));
        std::cout << result << remaining << std::endl;
    }
}
