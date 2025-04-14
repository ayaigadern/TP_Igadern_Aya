#ifndef Account_H
#define Account_H
#include<iostream>
#include <string>

class Account {
    private:

    static constexpr const char* def_name = "Unnamed Account";
    static constexpr const double def_balance = 0.0;

    protected:

    std::string nom;
    double balance;

    public:
        std::string get_nom() const {
            return nom;
        };
        double get_balance() const {
            return balance;
        };
        Account(std::string name = def_name, double balance = def_balance);
         bool deposit(double amount);
        virtual bool withdraw(double amount);
        friend std::ostream& operator<<(std::ostream& os, const Account& account);
};      

#endif