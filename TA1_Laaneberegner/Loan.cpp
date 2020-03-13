#include <Loan.h>
#include <iostream>
#include <math.h>


Loan::Loan(double debt, int years, int paymentsPerYear, double interestRate)
{
    setDebt(debt);
    setYears(years);
    setPaymentsPerYear(paymentsPerYear);
    setInterestRate(interestRate);
    calcPeriodicFee();
}

int Loan::getYears() const
{
    return mYears;

}

void Loan::setYears(int years)
{
    if(years > 0 && years <= 30)
    {
    mYears = years;
    }
    else
        std::cout << "Invalid argument" << std::endl;
}

int Loan::getPaymentsPerYear() const
{
    return mPaymentsPerYear;

}

void Loan::setPaymentsPerYear(int paymentsPerYear)
{
    if(paymentsPerYear > 0 && paymentsPerYear <= 12)
        {
            mPaymentsPerYear = paymentsPerYear;
        }
    else
    {
        std::cout << "invalid input, please choose a number between 1 and 12" << std::endl;
    }
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
}

double Loan::totalInterest() const
{
    return totalPayment() - getDebt();
}

double Loan::totalPayment() const
{
         return periodicFee * (mYears * mPaymentsPerYear);
}

double Loan::totalInterestTaxDeducted(double taxDeductionRate) const
{
    return totalInterest() * (taxDeductionRate/100);
}

void Loan::outputPeriodicalPayments(std::ostream &ost) const
{
    for (size_t i = 1; i < static_cast<size_t>((mYears * mPaymentsPerYear)+1); ++i)
    {
        ost << i << " Ydelse: " << periodicFee << " Restgæld " << static_cast<int>(((periodicFee * i) - totalPayment())) << std::endl;
    }
}

void Loan::calcPeriodicFee()
{
    periodicFee = mDebt * (mInterestRate/100)/(1 - (1/pow((1 + (mInterestRate/100)), static_cast<long double>(mYears * mPaymentsPerYear))));
}
