// COSC 1437 Lab 3
// Andrew Jacobson

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct  Product
{
	int productNumber;
	string name;
	double price;
	int unitsSold;
	double totalRevenue;
};

void sortArray(Product *[], int);

int main()
{
	ifstream salesFile;

	string inventoryName;
	int pNumber, uSold;
	double prices;

	Product * inventoryArray[100];
	Product * aProduct;

	int numProducts = 0;

	salesFile.open("sales.txt");

	if (salesFile) {

		while (salesFile >> pNumber)
		{
			salesFile >> inventoryName >> prices >> uSold;

			aProduct = new Product;
			aProduct->productNumber = pNumber;
			aProduct->name = inventoryName;
			aProduct->price = prices;
			aProduct->unitsSold = uSold;
			aProduct->totalRevenue = prices * uSold;

			inventoryArray[numProducts++] = aProduct;
		}
	}
	else {
		cout << "Error opening the file. \n";
	}

	sortArray(inventoryArray, numProducts);

	cout << "The top selling product is " << inventoryArray[numProducts - 1]->name << " with total sales of $" << 
		inventoryArray[numProducts - 1]->totalRevenue << endl;

	cout << "The second top selling product is " << inventoryArray[numProducts - 2]->name << " with total sales of $" <<
		inventoryArray[numProducts - 2]->totalRevenue << endl;
	

	system("pause");
	return 0;

}


void sortArray(Product *array[], int size) {
	bool swap;
	Product * temp;
	
	do {
		swap = false;
		for (int count = 0; count < (size - 1); count++) {
			if ((array[count]->totalRevenue) > (array[count + 1]->totalRevenue)) {
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
	
}