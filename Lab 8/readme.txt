COSC 1437 – Lab #08
Name Sorting and Searching
The attached file, CommonFemaleNames.txt, contains the top 1000 female names in the United States. The format is integer string where the integer is the popularity number (1 is most popular) and string is a female first name. The program is to read the list of names and create an array of objects. It then sorts the array in alphabetical order. The user enters a name, which the program searches for and then reports how common that name is. The program is to use two different search algorithms, a linear search and a binary search. It reports on how many microseconds it takes to find the name using each method.
Requirements
1. Each name and popularity number must be stored in a separate object.
2. The names on the list are all uppercase, but the program must find the name even if it is entered in lower case. Do this by converting the entered name to all caps.
3. It must give an appropriate message if the name entered is not on the list.
4. Both a linear and a binary search are required, for each name entered and the time it takes for each one reported.
5. Either the sort or the binary search must use a recursive method (Hint: a recursive binary search is easier than a recursive sort).
Suggestions
1. Chapters 8 and 19 have example C++ code for sorting and searching arrays.
2. Here is an example of getting the current time in microseconds.
auto start_time = chromo::high_resolution_clock::now();
ord = namelist.findBinary(name);
auto end_time = chrono::high_resolution_clock::now();
cout << "Binary search took " << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << " microseconds" << endl;
3. Note that on some systems the clock resolution is not fine enough and you may get 0 for the time. That is OK.
4. One way to organize this is in the UML below.
