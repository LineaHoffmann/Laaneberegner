#include <Loan.h>
#include <iostream>
#include <iomanip>
#include <math.h>


Loan::Loan(double debt, int years, int paymentsPerYear, double interestRate)
{
    //clling functions to set creation values
    setDebt(debt);
    setYears(years);
    setPaymentsPerYear(paymentsPerYear);
    setInterestRate(interestRate);

    //calculating periodic fee by the inputs
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
    //for-loop to iterate through all the periodic payments
    for (size_t i = 1; i < static_cast<size_t>((mYears * mPaymentsPerYear)+1); ++i)
    {
        //sending text to ost object to be printed
        //using io-manip to arrange into table
        ost << std::left << " | "
            << std::setw(7) << std::left << "Termin: "
            << std::setw(03) << std::right << i
            << std::left << " | "
            << std::setw(10) << std::left << " Ydelse: "
            << std::setw(10) << std::right << periodicFee
            << std::left << " | "
            << std::setw(10) << std::left << " Restgaeld "
            << std::setw(10) << std::right << static_cast<int>(((periodicFee * i) - totalPayment()))
            << std::left << " | " << std::endl;
    }
}

void Loan::calcPeriodicFee()
{
    periodicFee = mDebt * (mInterestRate/100)/(1 - (1/pow((1 + (mInterestRate/100)), static_cast<long double>(mYears * mPaymentsPerYear))));
}
