#ifndef ACCOUNT_H
#define ACCOUNT_H

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
};

#endif