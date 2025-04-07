#include "Bank.h"
#include <iostream>

Totaler::Totaler() : total(0.0f) {}

void Totaler::operator()(float amount) {
    total += amount;
}

float Totaler::getTotal() const {
    return total;
}

Bank::Bank() : nextAccountId(0) {}

Bank::~Bank() {
    for (auto& pair : accountsById) {
        delete pair.second;
    }
    accountsById.clear();
    accountsByName.clear();
}

void Bank::CreateAccount(int type, std::string name, float amount) {
    BankAccount* newAccount = nullptr;

    if (type == 0)
        newAccount = new CheckingAccount(amount, nextAccountId, name);
    else if (type == 1)
        newAccount = new SavingsAccount(amount, nextAccountId, name);
    else if (type == 2)
        newAccount = new InvestmentAccount(amount, nextAccountId, name);
    else
        return;

    accountsById[nextAccountId] = newAccount;
    accountsByName[name] = newAccount;
    nextAccountId++;
}

BankAccount* Bank::FindAccount(int id) {
    if (accountsById.count(id))
        return accountsById[id];
    return nullptr;
}

BankAccount* Bank::FindAccount(std::string name) {
    if (accountsByName.count(name))
        return accountsByName[name];
    return nullptr;
}

void Bank::Display() {
    for (auto& pair : accountsById) {
        pair.second->Display();
    }
}

void Bank::Display(int type) {
    for (auto& pair : accountsById) {
        BankAccount* account = pair.second;

        if (type == 0) {
            if (dynamic_cast<CheckingAccount*>(account) &&
                !dynamic_cast<InvestmentAccount*>(account)) {
                account->Display();
            }
        }
        else if (type == 1) {
            if (dynamic_cast<SavingsAccount*>(account) &&
                !dynamic_cast<InvestmentAccount*>(account)) {
                account->Display();
            }
        }
        else if (type == 2) {
            if (dynamic_cast<InvestmentAccount*>(account)) {
                account->Display();
            }
        }
    }
}

void Bank::RunFunctor(Totaler& functor) {
    for (auto& pair : accountsById) {
        functor(pair.second->getAmount());
    }
}