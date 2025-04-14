#ifndef Trust_Account_H
#define Trust_Account_H
#include<iostream>
#include "Savings_Account.h"

class Trust_Account: public Savings_Account{
    private:
   
    static constexpr double bonus_amount=50.0;
    static constexpr double bonus_threshold=5000.0;
    static constexpr double max_withdrawals=3;
    static constexpr double max_withdraw_percent=0.2;
    int num_withdrawals=0;

    public:

    Trust_Account(std::string name="Unnamed Trust Account", double balance=0, double int_rate=0);
    bool deposit(double amount);
    bool withdraw(double amount);
    friend std::ostream& operator<<(std::ostream& os, const Trust_Account& account);

};
#endif