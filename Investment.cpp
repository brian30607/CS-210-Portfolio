#include "Investment.h"
#include <iomanip>
#include <iostream>

using namespace std;

// Initializes an investment using the values entered by the user.
Investment::Investment(double t_initialInvestment, double t_monthlyDeposit,
                       double t_annualInterest, int t_numberOfYears)
    : m_initialInvestment(t_initialInvestment),
      m_monthlyDeposit(t_monthlyDeposit),
      m_annualInterest(t_annualInterest),
      m_numberOfYears(t_numberOfYears) {
}

// Calculates one month's interest using Airgead Banking's required formula.
double Investment::calculateMonthlyInterest(double t_balance, double t_deposit) const {
    return (t_balance + t_deposit) * ((m_annualInterest / 100.0) / 12.0);
}

// Displays the year-end balance and earned interest for a selected deposit amount.
void Investment::displayReport(double t_monthlyDeposit, const char* t_title) const {
    double balance = m_initialInvestment;

    cout << "\n" << t_title << endl;
    cout << string(66, '=') << endl;
    cout << left << setw(10) << "Year"
         << right << setw(25) << "Year End Balance"
         << setw(31) << "Year End Earned Interest" << endl;
    cout << string(66, '-') << endl;

    for (int year = 1; year <= m_numberOfYears; ++year) {
        double yearlyInterest = 0.0;

        for (int month = 1; month <= 12; ++month) {
            double monthlyInterest = calculateMonthlyInterest(balance, t_monthlyDeposit);
            yearlyInterest += monthlyInterest;
            balance += t_monthlyDeposit + monthlyInterest;
        }

        cout << left << setw(10) << year
             << right << fixed << setprecision(2)
             << setw(12) << "$" << setw(12) << balance
             << setw(19) << "$" << setw(12) << yearlyInterest << endl;
    }
}

// Shows investment growth when no additional monthly deposits are made.
void Investment::displayWithoutMonthlyDeposits() const {
    displayReport(0.0, "Balance and Interest Without Additional Monthly Deposits");
}

// Shows investment growth using the monthly deposit entered by the user.
void Investment::displayWithMonthlyDeposits() const {
    displayReport(m_monthlyDeposit, "Balance and Interest With Additional Monthly Deposits");
}
