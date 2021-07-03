// Lab 07 Andrew Jacobson
#include <iostream>
#include "Account.h"
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;


int main()
{

	ifstream bankFile;

	string junk;
	string command;
	int const SIZE = 10;
	int account;
	double amount;
	double minAmount;
	double feeRate;

	Account * accounts[SIZE] = { nullptr };

	bankFile.open("bank2.txt");

	if (bankFile) {
		cout << "File Opened." << endl;

		while (bankFile >> command) {
			if (command == "Savings" || command == "Checking") {
				bankFile >> account >> amount >> minAmount >> feeRate;
				if (accounts[account] == NULL) {
					if (command == "Savings") {
						accounts[account] = new Savings(account, amount, minAmount, feeRate);
						cout << command << " account number " << account << " created\n" <<
							"with an initial balance of $" << amount << endl;
					}
					else if (command == "Checking") {
						accounts[account] = new Checking(account, amount, minAmount, feeRate);
						cout << command << " account number " << account << " created\n" <<
							"with an initial balance of $" << amount << endl;
					}
				}
				else {
					cout << "That account number already exists." << endl;
					if (bankFile.peek() != '\n')
						getline(bankFile, junk);
				}
			}
			else if (command == "Withdraw") {
				bankFile >> account >> amount;
				if (accounts[account] != NULL) {
					accounts[account]->withdraw(amount);
					cout << "Withdrew $" << amount << " from account #" << account <<
						"\ncurrent balance is $" << accounts[account]->getBalance() << endl;
				}
				else {
					cout << "Invalid Account Number - " << account << endl;
					if (bankFile.peek() != '\n')
						getline(bankFile, junk);
				}
			}
			else if (command == "Deposit") {
				bankFile >> account >> amount;
				if (accounts[account] != NULL) {
					accounts[account]->deposit(amount);
					cout << "Deposited $" << amount << " into account #" << account <<
						"\ncurrent balance is $" << accounts[account]->getBalance() << endl;
				}
				else {
					cout << "Invalid Account Number - " << account << endl;
					if (bankFile.peek() != '\n')
						getline(bankFile, junk);
				}
			}
			else if (command == "Balance") {
				bankFile >> account;
				if (accounts[account] != NULL) {
					cout << "Current balance in account #" << account << " is $" <<
						accounts[account]->getBalance() << endl;
				}
				else {
					cout << "Invalid Account Number - " << account << endl;
					if (bankFile.peek() != '\n')
						getline(bankFile, junk);
				}
			}
			else if (command == "Close") {
				cout << "End of month processing complete." << endl;

				for (int i = 1; i < SIZE; i++) {
					if(accounts[i] != NULL)
						accounts[i]->closeMonth();
				}

			}
			else if (command == "Report") {
				for (int i = 1; i < SIZE; i++) {
					if (accounts[i] != NULL)
						accounts[i]->accountString();
				}
			}
			else {
				cout << "Unrecognizable Command - " << command << endl;
				if (bankFile.peek() != '\n')
					getline(bankFile, junk);
			}

		}

	}
	else {
		cout << "Error opening the file. \n";
	}


	system("pause");
	return 0;
}
