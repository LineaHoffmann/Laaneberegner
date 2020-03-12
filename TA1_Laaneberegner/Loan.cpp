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
    return 0;
}

double Loan::totalPayment() const
{
    double result{0};
    double payment{0};
    double remaining = mDebt;
    double tempCalc;

    std::cout << payment << " and " << result << " and " << remaining << std::endl;

    for ( size_t n = 1 ; n < (static_cast<size_t>(mYears) * mPaymentsPerYear) + 1 ; ++n)
    {
        tempCalc = 1/pow((1 + (mInterestRate/100)), static_cast<long double>(n));

        //calculation
        payment = mDebt * (mInterestRate/100)/(1 - tempCalc);
        std::cout << tempCalc << " payment: " << payment << std::endl;
    }

    return result;
}
