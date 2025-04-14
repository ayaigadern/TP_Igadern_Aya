#include <iostream>
#include "Account_Util.h"

// ==== ACCOUNT ====
void display(const std::vector<Account>& accounts) {
    std::cout << "\n=== Accounts ====================================" << std::endl;
    for (const auto& acc : accounts)
        std::cout << acc << std::endl;
}
void deposit(std::vector<Account>& accounts, double amount) {
    std::cout << "\n=== Depositing to Accounts ====================================" << std::endl;
    for (auto& acc : accounts)
        acc.deposit(amount);
}

void withdraw(std::vector<Account>& accounts, double amount) {
    std::cout << "\n=== Withdrawing from Accounts  ====================================" << std::endl;

    for (auto& acc : accounts)
        acc.withdraw(amount);
}

// ==== SAVINGS ====
void display(const std::vector<Savings_Account>& accounts) {
    std::cout << "\n=== Savings Accounts ============================" << std::endl;
    for (const auto& acc : accounts)
        std::cout << acc << std::endl;
}

void deposit(std::vector<Savings_Account>& accounts, double amount) {
    std::cout << "\n=== Depositing to Savings Accounts ====================================" << std::endl;
    for (auto& acc : accounts)
        acc.deposit(amount);
}

void withdraw(std::vector<Savings_Account>& accounts, double amount) {
    std::cout << "\n=== Withdrawing from Savings Accounts ====================================" << std::endl;
    for (auto& acc : accounts)
        acc.withdraw(amount);
}

// ==== CHECKING ====
void display(const std::vector<Checking_Account>& accounts) {
    std::cout << "\n=== Checking Accounts ============================" << std::endl;
    for (const auto& acc : accounts)
        std::cout << acc << std::endl;
}

void deposit(std::vector<Checking_Account>& accounts, double amount) {
    std::cout << "\n=== Depositing to Checking Accounts ============================" << std::endl;

    for (auto& acc : accounts)
        acc.deposit(amount);
}

void withdraw(std::vector<Checking_Account>& accounts, double amount) {
    std::cout << "\n=== Withdrawing from Checking Accounts ============================" << std::endl;
    for (auto& acc : accounts)
        acc.withdraw(amount);
}

// ==== TRUST ====
void display(const std::vector<Trust_Account>& accounts) {
    std::cout << "\n=== Trust Accounts ===============================" << std::endl;
    for (const auto& acc : accounts)
        std::cout << acc << std::endl;
}

void deposit(std::vector<Trust_Account>& accounts, double amount) {
    std::cout << "\n=== Depositing to Trust Accounts ============================" << std::endl;

    for (auto& acc : accounts)
        acc.deposit(amount);
}

void withdraw(std::vector<Trust_Account>& accounts, double amount) {
    std::cout << "\n=== Withdrawing from Trust Accounts ============================" << std::endl;
    for (auto& acc : accounts)
        acc.withdraw(amount);
}
