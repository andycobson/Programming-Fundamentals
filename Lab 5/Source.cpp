// Lab 05 Andrew Jacobson
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
	int account;
	double amount;

	Account * accounts[10] = {nullptr};

	bankFile.open("bank.txt");

	if (bankFile) {
		cout << "File Opened." << endl;

		while (bankFile >> command) {
			if (command == "Create") {
				bankFile >> account >> amount;
				if (accounts[account] == NULL) {
					accounts[account] = new Account(account, amount);
					cout << "Account number " << account << " created\n" <<
						"with an initial balance of $" << amount << endl;
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
			else if(command == "Balance") {
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
