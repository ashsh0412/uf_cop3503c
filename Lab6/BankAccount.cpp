#include "BankAccount.h"

BankAccount::BankAccount(int id, std::string name) : id(id), name(name) {}

std::string BankAccount::getName() const {
    return name;
}

int BankAccount::getID() const {
    return id;
}

CheckingAccount::CheckingAccount(float amount, int id, std::string name)
    : BankAccount(id, name), amount(amount) {}

void CheckingAccount::setAmount(float newAmount) {
    amount = newAmount;
}

void CheckingAccount::Display() const {
    std::cout << getName() << " (" << getID() << "):" << std::endl;
    std::cout << "\tChecking Account: $" << std::fixed << std::setprecision(2) << amount << std::endl;
}

void CheckingAccount::Deposit(float depositAmount) {
    if (depositAmount > 0) {
        amount += depositAmount;
    }
}

float CheckingAccount::getAmount() const {
    return amount;
}

bool CheckingAccount::Withdraw(float withdrawAmount) {
    if (withdrawAmount > 0 && withdrawAmount <= amount) {
        amount -= withdrawAmount;
        return true;
    }
    return false;
}

SavingsAccount::SavingsAccount(float amount, int id, std::string name)
    : BankAccount(id, name), amount(amount) {}

void SavingsAccount::setAmount(float newAmount) {
    amount = newAmount;
}

void SavingsAccount::Display() const {
    std::cout << getName() << " (" << getID() << "):" << std::endl;
    std::cout << "\tSavings Account: $" << std::fixed << std::setprecision(2) << amount << std::endl;
}

void SavingsAccount::Deposit(float depositAmount) {
    if (depositAmount > 0) {
        amount += depositAmount;
    }
}

float SavingsAccount::getAmount() const {
    return amount;
}

float SavingsAccount::CompoundEarnings(float percent) {
    if (percent > 0) {
        float earnings = amount * percent;
        amount += earnings;
        return earnings;
    }
    return 0.0f;
}

bool SavingsAccount::Transfer(CheckingAccount& account, float transferAmount) {
    if (transferAmount > 0 && transferAmount <= amount) {
        amount -= transferAmount;
        account.Deposit(transferAmount);
        return true;
    }
    return false;
}

InvestmentAccount::InvestmentAccount(float amount, int id, std::string name)
    : BankAccount(id, name), CheckingAccount(0, id, name), SavingsAccount(amount, id, name) {}

void InvestmentAccount::Display() const {
    std::cout << getName() << " (" << getID() << "):" << std::endl;
    std::cout << "\tTotal: $" << std::fixed << std::setprecision(2) << getAmount() << std::endl;
    std::cout << "\t\tImmediate Funds: $" << std::fixed << std::setprecision(2) << CheckingAccount::getAmount() << std::endl;
    std::cout << "\t\tInvestment: $" << std::fixed << std::setprecision(2) << SavingsAccount::getAmount() << std::endl;
}

void InvestmentAccount::Deposit(float depositAmount) {
    if (depositAmount > 0) {
        SavingsAccount::Deposit(depositAmount);
    }
}

float InvestmentAccount::getAmount() const {
    return CheckingAccount::getAmount() + SavingsAccount::getAmount();
}

bool InvestmentAccount::Transfer(float percent) {
    if (percent > 0 && percent <= 1.0) {
        float transferAmount = SavingsAccount::getAmount() * percent;
        if (transferAmount > 0) {
            SavingsAccount::setAmount(SavingsAccount::getAmount() - transferAmount);
            CheckingAccount::setAmount(CheckingAccount::getAmount() + transferAmount);
            return true;
        }
    }
    return false;
}

float InvestmentAccount::CompoundEarnings(float percent) {
    float earnings = SavingsAccount::CompoundEarnings(percent);
    if (earnings > 0) {
        CheckingAccount::setAmount(CheckingAccount::getAmount() + earnings);
        SavingsAccount::setAmount(SavingsAccount::getAmount() - earnings);
    }
    return earnings;
}