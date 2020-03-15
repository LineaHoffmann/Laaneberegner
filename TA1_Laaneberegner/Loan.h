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

    void calcPeriodicFee();

private:
    double mDebt, mInterestRate, periodicFee;
    int mYears, mPaymentsPerYear;



    //Array to hold values for different types of loans from https://www.totalkredit.dk/siteassets/dokumenter/privat/prisblad/prisblad.pdf
    static double loanDetailArr[10];

};

#endif // LOAN_H
