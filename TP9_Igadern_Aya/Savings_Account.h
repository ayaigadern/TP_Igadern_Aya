#ifndef Savings_Account_H
#define Savings_Account_H
#include<iostream>
#include "Account.h"

class Savings_Account: public Account{
    private:

    static constexpr const double def_int_rate=0;
    double int_rate;

        public:
            int get_int_rate() const {return int_rate;};
            Savings_Account(std::string name="Unnamed Savings Account", double balance=0, double int_rate=def_int_rate);
            bool deposit(double amount) ;
            bool withdraw(double amount) override;
            friend std::ostream& operator<<(std::ostream& os, const Savings_Account& account);

};


#endif