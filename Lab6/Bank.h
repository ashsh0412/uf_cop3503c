#pragma once

#include <map>
#include <string>
#include "BankAccount.h"

class Totaler {
private:
    float total;

public:
    Totaler();
    void operator()(float amount);
    float getTotal() const;
};

class Bank {
private:
    std::map<int, BankAccount*> accountsById;
    std::map<std::string, BankAccount*> accountsByName;
    int nextAccountId;

public:
    Bank();
    ~Bank();

    void CreateAccount(int type, std::string name, float amount);
    BankAccount* FindAccount(int id);
    BankAccount* FindAccount(std::string name);
    void Display();
    void Display(int type);
    void RunFunctor(Totaler& functor);
};