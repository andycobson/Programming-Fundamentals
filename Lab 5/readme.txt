COSC 1437 – Lab #05
Bank Program
This assignment uses the same account class created in Lab #4 with a more generally useful interface. It reads commands from a bank.txt file. Your program must process the following four commands.
Create account amount
Deposit account amount
Withdraw account amount
Balance account
In all of the above commands, account is an integer and amount is a double.
The following program behavior is required –
1. Valid account numbers are 1-9. This requires the program to have an array of references to Account objects.
2. If the first word on any line contains a command other than the four listed above, an error message should be displayed and that line ignored.
3. The create command creates a new account object with the given account number and initial balance. If an account already exists with that number an error message should be displayed and the command ignored.
4. The Deposit and Withdraw commands perform the indicated operation on an existing account. If no account with that number has been created, an error message is displayed and the command ignored.
5. The Balance command displays the balance of the requested account. No change to the account occurs. If no account with that number has been created, an error message is displayed and the command ignored.
Helpful Hints
 I have included a working example and sample bank.txt file along with the assignment. The .exe file and .txt files can be copied into any Windows directory to be run. You can explore other behaviors of the program by modifying the .txt file.
 Your Account class can be used exactly as it is although you will need to copy it to your new project for Lab 5 Your Account class can be used exactly as it is although you will need to copy it to your new project for Lab 5
 One way to skip the rest of a line if there is a bad command or account number is –
string junk;
if (inFile.peek() != '\n')
getline(inFile, junk);
 Test your program extensively to make sure it behaves as it should. I will use a different bank.txt file to test your programs.
 This is not an assignment that can be completed in a single day. Don’t put it off.
Upload: Your .h and .cpp files.
