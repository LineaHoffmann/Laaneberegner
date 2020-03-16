#include <Loan.h>
#include <iostream>
#include <iomanip>
#include <math.h>

/*
 * Constructor for the Loan objects.
 * Takes double debt, int years, int paymentYears, double InterestRate
*/
Loan::Loan(){}

Loan::Loan(double debt, int years, int paymentsPerYear, double interestRate)
{
    //calling functions to set creation values
    setDebt(debt);
    setYears(years);
    setPaymentsPerYear(paymentsPerYear);
    setInterestRate(interestRate);

    //calculating periodic fee by the inputs
    calcPeriodicFee();
}

/*
 * Get Years of the loan.
*/
int Loan::getYears() const
{
    return mYears;

}

/*
 * Set Years of the loan.
 * Years can't be less than 0 or bigger than 30 years
*/
void Loan::setYears(int years)
{
    if(years > 0 && years <= 30)
    {
    mYears = years;
    }
    else
        std::cout << "Ugyldigt argument" << std::endl;
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
        std::cout << "Ugyldig indtastning, venligst vælg en nummer mellem 1 og 12" << std::endl;
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
    //printing table headers
    ost << std::left << " | "
                << std::setw(8) << std::left << "Termin: "
                << std::left << " | "
                << std::setw(10) << std::left << " Ydelse: "
                << std::left << " | "
                << std::setw(15) << std::left << " Restgaeld: "
                << std::left << " | " << std::endl;
    //for-loop to iterate through all the periodic payments
    for (size_t i = 1; i < static_cast<size_t>((mYears * mPaymentsPerYear)+1); ++i)
    {
        //sending text to ost object to be printed
        //using io-manip to arrange into table, left/right justification used to make table prettier and width to define colomn width and setPrecision to always show 2 digits after the decimal point.
        ost << std::setprecision(2) << std::left << " | "
            << std::setw(8) << std::right << i
            << std::left << " | "
            << std::setw(10) << std::right << periodicFee
            << std::left << " | "
               //using round even to round to 2 significant decimals
            << std::setw(15) << std::right << std::fixed << ((round(100 * ((periodicFee * i) - totalPayment()))) / 100) * -1
            << std::left << " | " << std::endl;
    }
}

void Loan::calcPeriodicFee()
{
    periodicFee = mDebt * (mInterestRate/100)/(1 - (1/pow((1 + (mInterestRate/100)), static_cast<long double>(mYears * mPaymentsPerYear))));
}

void Loan::calcAllLoan(const double array[])
{
    //iterate through array setting intrestrate and calculation total payments ect. and printing.
    for(unsigned int i = 0; i < array.size; i++)
    {


    }

}
