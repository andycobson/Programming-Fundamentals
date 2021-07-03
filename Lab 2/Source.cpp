// Lab # 2 read file; Letter Count
// Andrew Jacobson
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void getMostLeast(int countArray[], int size, int &least, int &most);

int main()
{
	ifstream inputFile;
	string fLine;
	int mostFeq, leastFeq = 0;
	const int SIZE = 26;
	int countArray[SIZE] = { 0 };

	inputFile.open("letter_count.txt");
	//cout << "Reading data from the file.\n";

	if (inputFile) {
		//cout << "File has opened successfully." << endl;
		getline(inputFile, fLine);
		while (inputFile) {
			for (int i = 0; i < fLine.size(); i++) {
				if (islower(fLine[i])) fLine[i] = toupper(fLine[i]);
				countArray[int(fLine[i]) - 65] = countArray[int(fLine[i]) - 65] + 1;
			}
			getline(inputFile, fLine);
		}
		inputFile.close();
		getMostLeast(countArray, SIZE, leastFeq, mostFeq);
		cout << "The most common letter is " << char(mostFeq + 65) << " with " <<
			countArray[mostFeq] << " occurances." << endl;
		cout << "The least common letter is " << char(leastFeq + 65) << " with " <<
			countArray[leastFeq] << " occurances." << endl;
	}
	else {
		//Display error message
		cout << "Error opening the file.\n";
	}
	system("pause");
	return 0;
}

void getMostLeast(int countArray[], int size, int &least, int &most) {
	int minNum = countArray[0];
	int maxNum = countArray[0];
	int minElement, maxElement = 0;
	for (int i = 0; i < size; i++) {
		if (countArray[i] < minNum) {
			//Find minimum value and element in array
			minNum = countArray[i];
			minElement = i;
		}
		else if (countArray[i] > maxNum) {
			//Find maximum value and element in array
			maxNum = countArray[i];
			maxElement = i;
		}
	}
	least = minElement;
	most = maxElement;
}