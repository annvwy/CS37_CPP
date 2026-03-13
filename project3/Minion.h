/* Annette van Wyk -- Project 3*/

//Header file for Minion.cpp

#ifndef Minion_H
#define Minion_H

#include <iostream>
#include <string>


using namespace std;
class Minion
{
//Variables
  private:
    string name;
    float height;
    int eyes;
    int bananasOwned;
    static int minionCount;

  public:
 //Constructor
    Minion(string n, float h, int e, int b);
    
 // Getters
    string getName() const;
    int getBananas() const;

    // Operator overloads
    bool operator>(const Minion& other) const;
    bool operator<(const Minion& other) const;

    // Pre and post increment
    Minion& operator++();    // pre-increment
    Minion operator++(int);  // post-increment

    // Static function
    static void printMinionCount();

    // Friend function for output
    friend ostream& operator<<(ostream& os, const Minion& m);
};


#endif // Minion_Hpp