#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <chrono>
#include "CommonName.h"
#include "Name.h"
using namespace std;

int main() {
	
	ifstream nameListFile;
	string femaleName;
	bool stop = false;
	string userInput;
	Name namelist;
	int ord1, ord2, ordinalNumber;
	int i = 0;

	nameListFile.open("CommonFemaleNames.txt");

	if (nameListFile) {
		while (nameListFile >> ordinalNumber) {
			nameListFile >> femaleName;
			namelist.addName(new CommonName(ordinalNumber, femaleName));
		}
		cout << "The names have been read." << endl;
	}

	//namelist.printSort();
	namelist.sortNames(0, 999);
	cout << "The names have been sorted." << endl;


	while (stop == false) {
		cout << "Enter a female name, enter STOP to end: ";
		cin >> userInput;
		int i = 0;
		while (userInput[i]) {
			char c = userInput[i];
			userInput[i] = toupper(c);
			i++;
		}
		if (userInput == "STOP") {
			stop = true;
		}
		else {

			try {
				auto start_time = chrono::high_resolution_clock::now();
				ord1 = namelist.findLinear(userInput);
				auto end_time = chrono::high_resolution_clock::now();
				cout << "Linear search took " << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << " mciroseconds" << endl;

				start_time = chrono::high_resolution_clock::now();
				ord2 = namelist.findBinary(userInput);
				end_time = chrono::high_resolution_clock::now();
				cout << "Binary search took " << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << " mciroseconds" << endl;

				cout << userInput << " is the number " << ord2 << " most popular female name." << endl;
			}
			catch(Name::invalidInput){
				cout << userInput << " is not in list." << endl;
			}

		}

	}

	system("pause");
	return 0;
}