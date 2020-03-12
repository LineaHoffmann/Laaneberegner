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
    mInterestRate = rate;
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

    std::cout << payment << " and " << result << " and " << remaining << std::endl;

    for ( size_t n = 0; n < static_cast<size_t>(mYears); ++n)
    {
        payment = remaining * (1./(1 - (pow(1 + static_cast<double>(mInterestRate)/mPaymentsPerYear,-n))));
        result += payment;
        remaining -= payment;
        std::cout << payment << " and " << result << " and " << remaining << std::endl;
    }

    return result;
}
