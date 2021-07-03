#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using namespace std;

class Account
{
private:
	int id;
	double balance;
public:
	Account(int newID, double initialBalance);
	void setId(int);
	void setBalance(double);
	int getId() const { return id; }
	double getBalance() { return balance; }
	void withdraw(double);
	void deposit(double);
	virtual void accountString() = 0;
	virtual void closeMonth() = 0;
};

class Checking : public Account
{
private:
	double minBalance;
	double monFee;
public:
	Checking(int newID, double initialBalance, double minimumBalance, double monthelyFee);
	virtual void closeMonth();
	virtual void accountString();
};

class Savings : public Account
{
private:
	double interestRate;
	double minBalance;
public:
	Savings(int newID, double initialBalance, double minimumBalance, double annualInterestRate);
	virtual void closeMonth();
	virtual void accountString();
};

#endif