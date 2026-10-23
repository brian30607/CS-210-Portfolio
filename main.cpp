/*
 * Name: Brian P.
 * Course: CS 210
 * Project Two: Airgead Banking
 *
 * This program demonstrates the growth of an investment using monthly
 * compound interest. It displays results both with and without monthly
 * deposits so the user can compare the effect of regular contributions.
 */

#include "Investment.h"
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

// Reads a nonnegative decimal value and keeps prompting until input is valid.
double getNonnegativeDouble(const string& t_prompt) {
    double value;

    while (true) {
        cout << t_prompt;

        if (cin >> value && value >= 0.0) {
            return value;
        }

        cout << "Invalid input. Please enter a number that is 0 or greater." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Reads a positive whole number for the investment length.
int getPositiveYears(const string& t_prompt) {
    int years;

    while (true) {
        cout << t_prompt;

        if (cin >> years && years > 0) {
            return years;
        }

        cout << "Invalid input. Please enter a whole number greater than 0." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    char runAgain = 'Y';

    cout << fixed << setprecision(2);

    while (runAgain == 'Y' || runAgain == 'y') {
        cout << "\n**************************************" << endl;
        cout << "********** Airgead Banking ***********" << endl;
        cout << "************* Data Input *************" << endl;

        double initialInvestment =
            getNonnegativeDouble("Initial Investment Amount: $");
        double monthlyDeposit =
            getNonnegativeDouble("Monthly Deposit: $");
        double annualInterest =
            getNonnegativeDouble("Annual Interest (%): ");
        int numberOfYears =
            getPositiveYears("Number of Years: ");

        cout << "\nPress Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

        Investment investment(initialInvestment, monthlyDeposit,
                              annualInterest, numberOfYears);

        investment.displayWithoutMonthlyDeposits();
        investment.displayWithMonthlyDeposits();

        cout << "\nWould you like to test another investment scenario? (Y/N): ";
        cin >> runAgain;

        while (runAgain != 'Y' && runAgain != 'y' &&
               runAgain != 'N' && runAgain != 'n') {
            cout << "Please enter Y or N: ";
            cin >> runAgain;
        }
    }

    cout << "\nThank you for using the Airgead Banking investment calculator." << endl;
    return 0;
}
