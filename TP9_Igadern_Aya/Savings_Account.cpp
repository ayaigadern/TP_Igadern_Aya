#include "Savings_Account.h"
#include<iostream>
#include <iomanip>

Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
    :Account{name,balance}, int_rate{int_rate}{};

bool Savings_Account::deposit(double amount){
    if(amount<0){
        std::cout << "Failed Deposit of " << std::fixed << std::setprecision(2) << amount
        << " to " << *this << std::endl;
return false;
    }
    double taux=(int_rate*amount/100.0);
    balance+=amount+taux;
    std::cout << "Deposited " << std::fixed << std::setprecision(2) << amount
               << " to " << *this << std::endl;
    return true;
}
bool Savings_Account::withdraw(double amount) {
    return Account::withdraw(amount);  // Inherit the behavior from Account's withdraw
}
std::ostream& operator<<(std::ostream& os, const Savings_Account& account){
    os << "[Saving_Account: " << account.get_nom() << ": " << account.get_balance() << ", "<<account.get_int_rate()<<"]";
    return os;
}