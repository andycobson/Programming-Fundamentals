COSC 1437
Lab #3 Best Selling Items
Write a C++ program that reads sales data from a file called sales.txt. Each line of the file contains four data items;
1. A product number which is an integer
2. A product name which is a string no longer than 12 characters and which does not contain spaces
3. A unit price which is a double
4. A number of units sold which is an integer
The program will output the two products which generated the highest total revenue (unit price * number sold).
Your program must:
1. Read each line of the file storing the four items into the members of a dynamically allocated structure.
2. Store pointers to the structures in an array.
3. Sort the array of pointers by total revenue
4. Display the product name and total revenue of the top two products
5. The program must work for sales.txt files with anywhere from 2 to 100 products
Hints:
 Sections 5.11 and 12.1-6 illustrate reading from text files, but there is no good example of reading multiple items from the same line. Activity #3 will demonstrate this.
 Chapter 8 describes the bubble sort and selection sort. You may use which ever you choose. Note that you will need to modify the code to sort the pointers based on the total revenue.
 Using functions is not required for this assignment, but consider using functions to read the file and to sort the data.
Once you have tested the program, upload the .cpp file. Be sure to put your name in your program. A sample data file is attached to this assignment. The correct output for this file is below. Note that I will test your programs with a different file with a different number of products.
----------------------------------------------------------
The top selling product is Elec_Drill with total sales of $6031.08
The second top selling product is Hammer with total sales of $4800.95
