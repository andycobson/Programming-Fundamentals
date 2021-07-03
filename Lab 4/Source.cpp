// Lab 04 Andrew Jacobson
#include <iostream>
#include "Account.h"
#include <stdlib.h>
#include <time.h>
using namespace std;


int main()
{
	int id;
	double amount;

	srand(time(NULL));
	int account1Id = rand() % 300 + 1;
	int account2Id = rand() % 300 + 1;

	cout << "Please enter the initial balance for account number " << account1Id << ": $";
	cin >> amount;
	Account account1(account1Id, amount);

	cout << "Please enter the initial balance for account number " << account2Id << ": $";
	cin >> amount;
	Account account2(account2Id, amount);

	cout << "How much will you deposit in account number " << account1.getId() << "? $";
	cin >> amount;
	account1.deposit(amount);

	cout << "How much will you withdraw from account number " << account1.getId() << "? $";
	cin >> amount;
	account1.withdraw(amount);

	cout << "The current balance in account number " << account1.getId() << " is $" << account1.getBalance() << endl;

	cout << "How much will you deposit in account number " << account2.getId() << "? $";
	cin >> amount;
	account2.deposit(amount);

	cout << "How much will you withdraw from account number " << account2.getId() << "? $";
	cin >> amount;
	account2.withdraw(amount);

	cout << "The current balance in account number " << account2.getId() << " is $" << account2.getBalance() << endl;


	system("pause");
	return 0;
}
