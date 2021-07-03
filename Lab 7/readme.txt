COSC 1437 – Lab #07
Inheritance and Polymorphism
Based on the UML diagram from Lab #6, implement the three classes, Account, Checking, and Savings. Then implement a main program that reads commands from bank2.txt and carries out the commands using objects of these classes.
New Commands
Checking account initialBalance minimumBalance monthlyFee
Savings account initialBalance minimumBalance annualInterestRate
Deposit account amount
Withdraw account amount
Balance account
Close
Report
In the above commands, account is an integer between 1 and 9. All other arguments are doubles.
The close command performs the end of month functions for every existing account. The only output it produces is an “End of month processing complete” message. Note that Savings accounts have an annual interest rate, but at the end of the month only the monthly interest rate should be added. The annual interest rate is specified as a percentage, so a 7.5% interest rate is indicated as 7.5 in the Savings command.
The Report command lists all existing accounts and their balances, like –
Checking account #1 has a balance of $402.25
Savings account #2 has a balance of $53576.65
Tasks
1. Modify the Account class.
2. Implement and test your new subclasses.
3. Implement a main program which reads commands from a file and carries them out.
4. Test your program thoroughly. The instructor will use a different bank2.txt file to evaluate your program.
5. Submit the working classes and main program via the BlackBoard assignment.
Absolute Requirements
The Account class must be an abstract class with two pure virtual functions, closeMonth and accountString.
The Savings and Checking classes must be subclasses of Account
The bank must handle at least 10 accounts simultaneously with account numbers 1-9
Do not duplicate the balance or ID fields in the subclasses
The balance, withdrawal and deposit manipulation must use the methods in the base class Account.
Each action must display appropriate messages indicating that the action was completed.
The closeMonth and accountString functions must be called polymorphically. This means, they are called for each account without checking to see what kind of account it is being called on.
An implication of the last point is that there will be a single array of Account objects, some of which are Checking accounts and some of which are Savings accounts.
A working example of this program and a test bank2.txt file are attached to the assignment.
