#include "Account.h"
#include <iostream>
#include <cstdlib>
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
	if ((balance - amount) >= 0) {
		balance -= amount;
	}
	else {
		cout << "Do not have enough funds for withdraw.";
		exit(EXIT_FAILURE);
	}
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