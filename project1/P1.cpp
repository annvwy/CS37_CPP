/* Annette van Wyk -- Project 1 */

#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{

//storage 
    struct userAccount 
    {
        string username;
        string country;
        int age = 0;
        double accountBalance = 0;
    };

    double highestbalance = 0;
    double sumbalance = 0;
    int numHaiti = 0;
    bool u21 = false;
    int counter=0;

//number of accounts

    const int accmax = 30;
    userAccount accounts[accmax];

//prompt

    cout << "Please enter information to database in the format of <username> <country> <age> <accountBalance>, separated each user by a newline:\n" << endl;

//inputting account details
    while(counter<accmax && 
        cin >> accounts[counter].username 
            >> accounts[counter].country 
            >> accounts[counter].age 
            >> accounts[counter].accountBalance)
            {
                counter++;
            }
        
//processing

    //determine highest account balance and sum of account balances
    
    highestbalance = accounts[0].accountBalance; //initialize
    sumbalance += accounts[0].accountBalance; //include excluded balance in sum

    for (int i=1 ; i<counter ; i++) 
    {
        if (accounts[i].accountBalance > highestbalance)
        {
            highestbalance = accounts[i].accountBalance;
        }

        sumbalance += accounts[i].accountBalance;
    }

    cout << "Q: What is the highest account balance among all users?" << endl;
    cout << "A: The highest account balance is: $" << fixed << setprecision(2) << highestbalance << endl;

    cout << "\nQ: What is the sum of the account balance of all users?" << endl;
    cout << "A: The sum of all account balances is: $" << fixed << setprecision(2) << sumbalance << endl;

    //how many users from Haiti

    for (int i=0 ; i<counter ; i++) 
    {
        if (accounts[i].country == "Haiti")
        {
            numHaiti++;
        }

    //any users under 21? Y/N

        if (accounts[i].age < 21)
        {
            u21 = true;
        }
    }

    cout << "\nQ: How many users come from Haiti?" << endl;
    cout << "A: There are " << numHaiti << " users from Haiti." << endl;

    cout << "\nQ: Are there any users younger than 21?" << endl;
    if (u21 == true)
    {
        cout << "A: Yes, there are users that are younger than 21." << endl;
    } else {
        cout << "A: No, there are not users that are younger than 21." << endl;
    }
    
    return 0;

}

/* TEST RUNS

1:

Please enter information to database in the format of <username> <country> <age> <accountBalance>, separated each user by a newline:

Hanzo Japan 38 34.99
Mei China 31 75
Brigitte Sweden 20 24.5
Mercy Switzerland 37 242.35
Sigma Netherlands 62 1324
Baptiste Haiti 36 325
Kiriko Japan 21 35
^Z
Q: What is the highest account balance among all users?
A: The highest account balance is: $1324.00

Q: What is the sum of the account balance of all users?
A: The sum of all account balances is: $2060.84

Q: How many users come from Haiti?
A: There are 1 users from Haiti.

Q: Are there any users younger than 21?
A: Yes, there are users that are younger than 21.


2:

Please enter information to database in the format of <username> <country> <age> <accountBalance>, separated each user by a newline:

Hanzo Haiti 38 34.99
Mei China 21 75.0
Brigitte Sweden 23 24.5
Mercy Switzerland 15 242.35
Sigma Haiti 62 1399.346
Baptiste Haiti 36 325.0
^Z
Q: What is the highest account balance among all users?
A: The highest account balance is: $1399.35

Q: What is the sum of the account balance of all users?
A: The sum of all account balances is: $2101.19

Q: How many users come from Haiti?
A: There are 3 users from Haiti.

Q: Are there any users younger than 21?
A: Yes, there are users that are younger than 21.


3:

Please enter information to database in the format of <username> <country> <age> <accountBalance>, separated each user by a newline:

Hanzo Japanese 38 34.99
Mei Chinese 21 75.0
Brigitte Swedish 23 24.5
Mercy Switzerland 37 242.35
Sigma Netherlands 62 1324
^Z
Q: What is the highest account balance among all users?
A: The highest account balance is: $1324.00

Q: What is the sum of the account balance of all users?
A: The sum of all account balances is: $1700.84

Q: How many users come from Haiti?
A: There are 0 users from Haiti.

Q: Are there any users younger than 21?
A: No, there are not users that are younger than 21.
*/