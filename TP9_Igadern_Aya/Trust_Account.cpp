#include "Trust_Account.h"
#include<iostream>
#include <iomanip>

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    :Savings_Account{name,balance,int_rate}{};

    bool Trust_Account::deposit(double amount) {
        if(amount<0){
            std::cout << "Failed Deposit of " << std::fixed << std::setprecision(2) << amount
            << " to " << *this << std::endl;
    return false;
        }
    
        if (amount >= bonus_threshold) {
            balance += bonus_amount;
        }
    
        double taux=(get_int_rate()*amount/100.0);
    balance+=amount+taux;
    bool success= true;
        if (success) {
            std::cout << "Deposited " << std::fixed << std::setprecision(2)
                      << amount << " to " << *this << std::endl;
        } else {
            std::cout << "Failed deposit of " << std::fixed << std::setprecision(2)
                      << amount << " to " << *this << std::endl;
        }
        return success;
    }
    

    bool Trust_Account::withdraw(double amount){
        if (num_withdrawals >= max_withdrawals ||amount > balance * max_withdraw_percent ) {
            std::cout << "Failed Withdrawal of " << std::fixed << std::setprecision(2)
                      << amount << " from " << *this << std::endl;
            return false;
        }
        ++num_withdrawals;
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
    

std::ostream& operator<<(std::ostream& os, const Trust_Account& account){
    os << "[Trust_Account: " << account.get_nom() << ": " << account.get_balance() << ", "<<account.get_int_rate()<<"%, withdrawals: "<< account.num_withdrawals<<"]";
    return os;
}



