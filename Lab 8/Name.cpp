#include "Name.h"
#include <iostream>

Name::Name()
{
	nextName = 0;
}

void Name::addName(CommonName *name) {
	namepair[nextName] = name;
	nextName++;

}


void Name::printSort() {
	cout << "Printing the sorted list to make sure it is sorted....." << endl;
	for (int i = 0; i < 1000; i++) {
		if (namepair[i] != NULL) {
			cout << i << " " << namepair[i]->getOrdinal() << " " << namepair[i]->getName() << endl;
		}
		else {
			cout << i << " NULL" << endl;
		}
	}
}

void Name::sortNames(int start, int end) {
	//Quick Sort
	int pivotPoint;

	if (start < end) {
		
		pivotPoint = partition(start, end);
		sortNames(start, pivotPoint - 1);
		sortNames(pivotPoint + 1, end);
	}
	
}

int Name::partition(int start, int end) {
	int pivotIndex, mid;
	string pivotValue;
	CommonName* temp;

	mid = (start + end) / 2;
	temp = namepair[start];
	namepair[start] = namepair[mid];
	namepair[mid] = temp;

	pivotIndex = start;
	pivotValue = namepair[start]->getName();
	for (int scan = start + 1; scan <= end; scan++) {
		if (namepair[scan]->getName() < pivotValue) {
			pivotIndex++;
			temp = namepair[pivotIndex];
			namepair[pivotIndex] = namepair[scan];
			namepair[scan] = temp;
		}
	}
	temp = namepair[start];
	namepair[start] = namepair[pivotIndex];
	namepair[pivotIndex] = temp;
	return pivotIndex;
}

int Name::findLinear(string name) {
	int index = 1;
	int position = -1;
	bool found = false;

	while (index < 1000 && !found) {
		if (namepair[index]->getName() == name) {
			found = true;
			position = index;
		}
		index++;
	}
	//throw
	if (position != -1) {
		return namepair[position]->getOrdinal();
	}
	else {
		throw invalidInput();
	}
}

int Name::findBinary(string name) {
	int first = 1,			
		last = 1000 - 1,	
		middle,				
		position = -1;		
	bool found = false;			

	while (!found && first <= last) {
		middle = (first + last) / 2;
		if (namepair[middle]->getName() == name) 
		{
			found = true;
			position = middle;
		}
		else if (namepair[middle]->getName() > name)
		{
			last = middle - 1;
		}
		else {
			first = middle + 1;
		}

	}
	//throw
	if (position != -1) {
		return namepair[position]->getOrdinal();
	}
	else {
		throw invalidInput();
	}
}
