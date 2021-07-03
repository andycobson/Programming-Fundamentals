COSC 1437 
Lab #2 Letter Count 
Write a C++ program that reads text from a file called letter_count.txt. The program determines which alphabetic character occurs most frequently in the text and which alphabetic character appears least frequently in the text. 
Your program must: 
1.   Read each line of the file, no matter how many lines there are.
2.   Display an appropriate message if the letter_count.txt file is not found.
3.   Count both lower case and upper case variants as the same character. In the text,“This is the time for all good men to come to the aid of their country”, the letter Toccurs 7 times.
4.   Ignore non-alphabetic characters, such as space, period, apostrophe, etc.
5.   Display the most common letter in the file and its number of occurrences.
6.   Display the least common letter in the file and its number of occurrences.
7.   If there is a tie for the most (or least) common letter, the program only needs todisplay one of the letters which was most (or least) common.
8.   For this program, only the C++ string class may be used. C-strings or C-stringfunctions may not be used for this assignment.
9.   Your program must include at least one function that uses one or more referencevariables as parameters.
10. No global variables may be used for this program.
Hints: 
The toupper function can be used to convert lowercase letters to uppercase.
The isalpha function can be used to determine if the character is an alphabeticcharacter.
You can use a 26 element integer array to keep track of the letter counts bysubtracting ‘A’ from the Ascii value of the character. Like, letterCount[letter –‘A’] = letterCount[letter –‘A’] + 1;
Once you have tested the program, upload the .cpp file. Be sure to put your name in your program. A sample file is attached to this assignment. The correct output for this file is below. Note that I will test your programs with a different text file. 
----------------------------------------------------------
The most common letter is E with 147 occurances. 
The least common letter is J with 0 occurances.
