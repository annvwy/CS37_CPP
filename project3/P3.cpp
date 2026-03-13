/* Annette van Wyk -- Project 3*/

//Main function for project 3

#include <iostream>
#include <fstream>
#include "Minion.h"

using namespace std;
int main()
{
//Read file
    string minionsFileName = "minions.txt";
    ifstream minionsFile(minionsFileName);

//Check file
    if (minionsFile.fail()) 
    {
        cout << "File failed to open." << endl;
        return 0;
    }

//Initialize minion with name, height, eyes, and bananasOwned.
    string name;
    float height;
    int eyes;
    int bananas;

    minionsFile >> name >> height >> eyes >> bananas;
    const Minion minion1(name, height, eyes, bananas);

    minionsFile >> name >> height >> eyes >> bananas;
    Minion minion2(name, height, eyes, bananas);

    minionsFile >> name >> height >> eyes >> bananas;
    Minion minion3(name, height, eyes, bananas);

//Find the taller minion
    if (minion1 > minion2) 
    {
       cout << minion1.getName() << " is taller than " << minion2.getName();
    } 
    if (minion2 < minion3) 
    {
        cout << minion3.getName() << " is taller than " << minion2.getName();
    }
    cout << endl << endl;

// Minion 2 bananas
    cout << minion2;
    cout << minion2.getName() << " getting bananas.\n";
    cout << "The minion now has " << (++(++minion2)).getBananas() << " banana(s).\n" << endl;

// Minion 3 bananas
    cout << minion3;
    cout << minion3.getName() << " getting bananas.\n";
    cout << "Before getting bananas, the minion had " << minion3++.getBananas() << " banana(s).\n";
    cout << "After getting bananas, the minion has " << minion3.getBananas() << " banana(s).\n" << endl;

// Print minion count
    Minion::printMinionCount();

    return 0;
}

/*
TEST RUN OUTPUT:

Kevin is taller than Stuart

The minion Stuart is 25.5 inches tall, has 1 eye(s), and owns 4 banana(s).
Stuart getting bananas.
The minion now has 6 banana(s).

The minion Bob is 23.8 inches tall, has 2 eye(s), and owns 0 banana(s).
Bob getting bananas.
Before getting bananas, the minion had 0 banana(s).
After getting bananas, the minion has 1 banana(s).
*/