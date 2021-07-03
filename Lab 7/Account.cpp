#include "Account.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


Account::Account(int newID, double initialBalance)
{
	id = newID;
	balance = initialBalance;

}

void Account::setId(int newID) {
	if (newID >= 0) {
		id = newID;
	}
	else {
		cout << "Invalid id...";
		exit(EXIT_FAILURE);
	}
}

void Account::setBalance(double newBalance) {
	if (newBalance >= 0.0) {
		balance = newBalance;
	}
	else {
		cout << "Invalid balance...";
		exit(EXIT_FAILURE);
	}
}

void Account::withdraw(double amount) {
	balance -= amount;
}

void Account::deposit(double amount) {
	if (amount >= 0) {
		balance += amount;
	}
	else {
		cout << "Please insert funds.";
		exit(EXIT_FAILURE);
	}
}


Checking::Checking(int newID, double initialBalance, double minimumBalance, double monthelyFee):Account(newID, initialBalance)
{
	minBalance = minimumBalance;
	monFee = monthelyFee;
}

void Checking::closeMonth()
{
	if (getBalance() < minBalance) {
		withdraw(monFee);
	}
}

void Checking::accountString()
{
	cout << "Checking Account #" << to_string(getId()) << " has a balance of $" << to_string(getBalance()) << endl;
}


Savings::Savings(int newID, double initialBalance, double minimumBalance, double annualInterestRate):Account(newID, initialBalance)
{
	minBalance = minimumBalance;
	interestRate = annualInterestRate;
}

void Savings::closeMonth()
{
	withdraw(((interestRate / 12) / -100) * getBalance());

}

void Savings::accountString()
{
	cout << "Savings Account #" << to_string(getId()) << " has a balance of $" << to_string(getBalance()) << endl;
}
