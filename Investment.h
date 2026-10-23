#ifndef AIRGEAD_BANKING_INVESTMENT_H_
#define AIRGEAD_BANKING_INVESTMENT_H_

class Investment {
public:
    Investment(double t_initialInvestment, double t_monthlyDeposit,
               double t_annualInterest, int t_numberOfYears);

    void displayWithoutMonthlyDeposits() const;
    void displayWithMonthlyDeposits() const;

private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_numberOfYears;

    double calculateMonthlyInterest(double t_balance, double t_deposit) const;
    void displayReport(double t_monthlyDeposit, const char* t_title) const;
};

#endif // AIRGEAD_BANKING_INVESTMENT_H_
