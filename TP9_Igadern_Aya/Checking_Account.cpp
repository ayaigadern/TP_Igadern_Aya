#include "Checking_Account.h"
#include<iostream>
#include <iomanip>

Checking_Account::Checking_Account(std::string name, double balance)
    :Account{name,balance}{};

bool Checking_Account::withdraw(double amount){
    double total=amount+per_check_fee;

    if(total>balance){
        std::cout<<"Failed Withdrawal of "<<std::fixed<<std::setprecision(2)<< amount<<" from "<<*this<<std::endl;
        return false;
    }
    balance-=total;
    std::cout<<" Withdrew "<<std::fixed<<std::setprecision(2)<< amount<<" from "<<*this<<std::endl;
    return true;
}
std::ostream& operator<<(std::ostream& os, const Checking_Account& account){
    os<<"[checking:"<<account.get_nom()<<": "<<account.get_balance()<<"]";
    return os;
}