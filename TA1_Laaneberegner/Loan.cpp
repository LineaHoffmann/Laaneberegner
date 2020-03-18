#include <Loan.h>
#include <iostream>
#include <iomanip>
#include <math.h>

//Constructor
Loan::Loan(){}

// Constructor for the Loan objects.
// Takes double debt, int years, int paymentYears, double InterestRate
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


// Get Years of the loan.
int Loan::getYears() const
{
    return mYears;
}


// Set Years of the loan.
// Years can't be less than 0 or bigger than 30 years (normally limited to 1 to 30 years)
void Loan::setYears(int years)
{
    if(years > 0 && years <= 30)
    {
    mYears = years;
    }
    else
        std::cout << "Ugyldigt argument" << std::endl;
}

// Gets payment per year
int Loan::getPaymentsPerYear() const
{
    return mPaymentsPerYear;

}

// Sets the payment per year. If user insert invalid number, user gets an error
// Can't be more than 12, becuase normally pays monthly.
void Loan::setPaymentsPerYear(int paymentsPerYear)
{
    if(paymentsPerYear > 0 && paymentsPerYear <= 12)
        {
            mPaymentsPerYear = paymentsPerYear;
        }
    else
    {
        std::cout << "Ugyldig indtastning, venligst vaelg en nummer mellem 1 og 12" << std::endl;
    }
}

// Get the debt
double Loan::getDebt() const
{
    return mDebt;
}

// Set the debt, uses a doube as parameter
void Loan::setDebt(double debt)
{
    mDebt = debt;
}

// Get interest rate
double Loan::getInterestRate() const
{
    return mInterestRate;
}

// Set interest rate, takes double as parameter
//
void Loan::setInterestRate(double rate)
{
   mInterestRate = rate/mPaymentsPerYear;
}

// calculates the total interest
// takes payment - debt and returns the result.
double Loan::totalInterest() const
{
    return totalPayment() - getDebt();
}

// calculates total payment
// takes periodic fee * (years * payments per year) retuns the result
double Loan::totalPayment() const
{
         return mperiodicFee * (mYears * mPaymentsPerYear);
}

// calculates the total interest after tax deduction
// takes total interest * tac deduction / 100 and substracs from total interest
double Loan::totalInterestTaxDeducted(double taxDeductionRate) const
{
    return totalInterest() - (totalInterest() * (taxDeductionRate/100));
}

// prints out a tableveiw for all the payments of the loan
void Loan::outputPeriodicalPayments(std::ostream &ost) const
{
    double tempPV{0}, tempR = mDebt;
    //printing table headers

    ost << "Tabel over ydelsesforløbet med indtastede vaerdier:" <<std::endl;
    ost << std::left << " | "
                << std::setw(8) << std::left << "Termin: "
                << std::left << " | "
                << std::setw(10) << std::left << " Ydelse: "
                << std::left << " | "
                << std::setw(10) << std::left << " Rentebidrag: "
                << std::left << " | "
                << std::setw(15) << std::left << " Afdrag: "
                << std::left << " | "
                << std::setw(15) << std::left << " Restgaeld: "
                << std::left << " | " << std::endl;
    //for-loop to iterate through all the periodic payments
    for (size_t i = 1; i < static_cast<size_t>((mYears * mPaymentsPerYear)+1); ++i)
    {
        tempPV = (mperiodicFee) * (1 - (1/pow((1 + (mInterestRate/100)), static_cast<long double>((mYears * mPaymentsPerYear)) - i)))/(mInterestRate/100);
        //sending text to ost object to be printed
        //using io-manip to arrange into table, left/right justification used to make table prettier and width to define colomn width and setPrecision to always show 2 digits after the decimal point.
        ost << std::setprecision(2) << std::fixed
            << std::left << " | "
            << std::setw(8) << std::right << i
            << std::left << " | "
            << std::setw(10) << std::right << (lrint( 100 * mperiodicFee)) / 100. //lrint used to round after bankersround priciple, 100. used to force decimal division
            << std::left << " | "
            << std::setw(14) << std::right << (lrint( 100 * (tempR * (mInterestRate/100)))) / 100.
            << std::left << " | "
            << std::setw(15) << std::right << (lrint( 100 * ((((tempPV + mperiodicFee) * mInterestRate/100) - mperiodicFee) * -1))) / 100.
            << std::left << " | "
               //using round even to round to 2 significant decimals
            << std::setw(15) << std::right << tempPV
            << std::left << " | " << std::endl;
        tempR = tempPV;
    }
}

// calculates the periodic fee per termin
void Loan::calcPeriodicFee()
{
    mperiodicFee = mDebt * (mInterestRate/100)/(1 - (1/pow((1 + (mInterestRate/100)), static_cast<long double>(mYears * mPaymentsPerYear))));
}

//Calculates and print loan types given in the array.
// takes an double array and size_t numberOfElements as parameters.
void Loan::calcAllLoan(const double array[], const size_t numberOfElements)
{
    //iterate through array setting intrestrate and calculat total payments ect. and printing.
    for (unsigned int i = 0; i < numberOfElements; i++)
    {
        setInterestRate(*(array + i));
        calcPeriodicFee();
        std::cout << "Renten: " << array[i] << " Total tilbagebetalingsbeloeb: " << totalPayment() <<  " Samlet rentebeloeb efter fradrag: " << totalInterestTaxDeducted(30.6) << std::endl;
    }


}
