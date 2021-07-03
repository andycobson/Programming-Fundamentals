// Lab # 1 Grade Median by Andrew Jacobson
// Store the grades in an array.
// Have a function that inputs the grades, stores them in an array and returns the number of grades.
// Handle up to 20 grades.
// Use a function that sorts an array of grades.
// Have a seperate func that accepts sorted array and num of grades and returns median of grades.
// 85.2, 92.3, 78.0, 51.5, 91.6, 87.0
#include <iostream>
using namespace std;


void sortArray(double[], int);
void showArray(const double[], int);
double gradeMedian(double[], int);

int main()
{
	int size;
	double grades[20];
	double value;
	double mediumVal;

	cout << "Please enter the number of grades: ";
	cin >> size;

	for (int count = 0; count < size; count++) {
		cout << "Grade " << count + 1 << ": ";
		cin >> value;
		grades[count] = value;
	}

	sortArray(grades, size);

	mediumVal = gradeMedian(grades, size);

	cout << "\nThe median grade is " << mediumVal << endl;

	system("pause");
	return 0;
}

void sortArray(double array[], int size) {
	bool swap;
	double temp;

	do {
		swap = false;
		for (int count = 0; count < (size - 1); count++) {
			if (array[count] > array[count + 1]) {
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

void showArray(const double array[], int size) {
	for (int count = 0; count < size; count++)
		cout << array[count] << " ";
	cout << endl;
}

double gradeMedian(double array[], int size) {
	double mediumNum = 0.0;
	if (size % 2 == 0) {
		int midVal = size / 2;
		int nexVal = midVal - 1;

		mediumNum = ((array[midVal] - array[nexVal]) / 2) + array[nexVal];
	}
	else {
		mediumNum = (array[(size / 2)]);
	}
	
	return mediumNum;
}