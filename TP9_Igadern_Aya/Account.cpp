#include "Account.h"
#include<iostream>
#include <iomanip>

Account::Account(std::string name, double balance)
    :nom{name}, balance{balance}{};

bool Account::deposit(double amount){
    if(amount>=0){
        balance+=amount;
        std::cout << "Deposited " << std::fixed << std::setprecision(2) << amount
        << " to " << *this << std::endl;
        return true;
    }
    std::cout << "Failed Deposit of " << std::fixed << std::setprecision(2) << amount
    << " to " << *this << std::endl;
    return false;

}

bool Account::withdraw(double amount){
    if(balance>=amount){
        balance-=amount;
        std::cout << "Withdrew " << std::fixed << std::setprecision(2) << amount
        << " from " << *this << std::endl;
        return true;
    }
    std::cout << "Failed Withdrawal of " << std::fixed << std::setprecision(2) << amount
    << " from " << *this << std::endl;
    return false;
}

std::ostream& operator<<(std::ostream& os, const Account& account){
    os << "[Account: " << account.get_nom() << ": " << account.get_balance() << "]";
    return os;
}