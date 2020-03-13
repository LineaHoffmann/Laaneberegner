#ifndef LOAN_H
#define LOAN_H
#include <ostream>

class Loan {
public:
    Loan();

    // Skal initialisere Loan til at have
    Loan(double debt, int years, int paymentsPerYear, double interestRate);

    // Returns the number of years the loan lasts
    int getYears() const;
    void setYears(int years);

    // Amount of payments per year (terminer)
    int getPaymentsPerYear() const;
    void setPaymentsPerYear(int paymentsPerYear);

    // Debt
    double getDebt() const;
    void setDebt(double debt);

    // Rente
    double getInterestRate() const;
    void setInterestRate(double rate);

    // Calculate the total interest of a loan for all the years
    double totalInterest() const;

    // Calculate the total repayment of a loan including the interests
    double totalPayment() const;

    // Calculate the total net interest of a loan after tax refund
    double totalInterestTaxDeducted(double taxDeductionRate) const;

    // Output the periodical payments with unpaid balance, paid interest and repayment of each payment to stream object ost
    void outputPeriodicalPayments(std::ostream& ost) const;
private:
    double mDebt, mInterestRate;
    int mYears, mPaymentsPerYear;

    friend double rounding(double &input);
};

double rounding(double &amount)
{

    int64_t rounded = ((amount) / 100) * 10;  // Rounded down before *10
    int64_t trueval = ((amount* 10) / 100);
    int64_t rounded;


    return rounded;
}

#endif // LOAN_H
