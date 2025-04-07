#pragma once

#include <iostream>
#include <string>
#include <iomanip>

class BankAccount {
private:
    int id;
    std::string name;

public:
    BankAccount(int id, std::string name);
    virtual ~BankAccount() = default;

    std::string getName() const;
    int getID() const;

    virtual void Display() const = 0;
    virtual void Deposit(float amount) = 0;
    virtual float getAmount() const = 0;
};

class CheckingAccount : virtual public BankAccount {
private:
    float amount;

protected:
    void setAmount(float amount);

public:
    CheckingAccount(float amount, int id, std::string name);

    void Display() const override;
    void Deposit(float amount) override;
    float getAmount() const override;

    bool Withdraw(float amount);
};

class SavingsAccount : virtual public BankAccount {
private:
    float amount;

protected:
    void setAmount(float amount);

public:
    SavingsAccount(float amount, int id, std::string name);

    void Display() const override;
    void Deposit(float amount) override;
    float getAmount() const override;

    float CompoundEarnings(float percent);
    bool Transfer(CheckingAccount& account, float amount);
};

class InvestmentAccount : public CheckingAccount, public SavingsAccount {
public:
    InvestmentAccount(float amount, int id, std::string name);

    void Display() const override;
    void Deposit(float amount) override;
    float getAmount() const override;

    bool Transfer(float percent);
    float CompoundEarnings(float percent);
};