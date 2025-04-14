#ifndef Checking_Account_H
#define Checking_Account_H
#include<iostream>
#include "Account.h"

class Checking_Account: public Account{
    public:
    static constexpr const double per_check_fee=1.50;
    Checking_Account(std::string name="Unnamed checking Account", double balance=0);
    bool withdraw(double amount);

    friend std::ostream& operator<<(std::ostream& os, const Checking_Account& account);

};
#endif