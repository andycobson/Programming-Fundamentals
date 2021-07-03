COSC 1437 – Lab #06
Inheritance and Polymorphism
This assignment starts with the Account class from Labs 4 and 5. Our new and improved bank has two kinds of accounts, savings, and checking. In addition to an ID and a balance, savings accounts have an annual interest rate and a minimum balance. Checking accounts have a minimum balance and a monthly fee. Withdrawals and deposits can be made to both kinds of accounts. At the end of each month, savings accounts pay interest, but only if the account’s balance is above the minimum. Also at the end of each month, a fee is deducted from each checking account, but the fee is waived if the account’s balance is over the minimum.
Tasks
1. Create a complete UML diagram which shows the relationships between the three classes, Account, Savings, and Checking and all of the fields and methods in each. The only modifications required to the Account class is the addition of two abstract methods called closeMonth and accountString.
2. The closeMonth function performs the appropriate end of month action for its class.
3. The accountString function returns a string which indicates the type of account, the account number, and the current balance, like –
Checking account #1 has a balance of $402.25
4. The Savings and Checking classes inherit the account number and balance variables along with the functions from the Account class.
5. The Savings and Checking classes each have a minimum balance variable and an annual interest rate (or monyhly fee). They need constructors and concrete implementations of the closeMonth and accountString functions.
6. I recommend using Raptor’s Object Oriented Mode to do this, but you may do it in Word, PowerPoint, or Visio.
7. For this assignment only the UML diagram is required. Lab #7 will require students to implement these classes along with a main program.
New Commands
Like Lab #5, Lab #7 will read commands from a file. The UML diagram for Lab #6 should include all of the variables and functions necessary to implement these commands.
Checking account initialBalance minimumBalance monthlyFee
Savings account initialBalance minimumBalance annualInterestRate
Deposit account amount
Withdraw account amount
Balance account
Close
Report
In the above commands, account is an integer between 1 and 9. All other arguments are doubles.
The close command performs the end of month functions for every existing account. The only output it produces is an “End of month processing complete” message.
The Report command lists all existing accounts and their balances, like –
Checking account #1 has a balance of $402.25
Savings account #2 has a balance of $53576.65
