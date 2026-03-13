/* Annette van Wyk -- Project 3*/

//Implementation of class "Minion"


#include "Minion.h"

//Initialize static member
int Minion::minionCount = 0;

//Constructor
Minion::Minion(string n, float h, int e, int b)
{
    name=n;
    height=h;
    eyes=e;
    bananasOwned=b;

    minionCount++;
}

//Getters
string Minion::getName() const 
{
    return name;
}

int Minion::getBananas() const 
{
    return bananasOwned;
}

//Compare heights
bool Minion::operator>(const Minion& other) const 
{
    return height > other.height;
}

bool Minion::operator<(const Minion& other) const 
{
    return height < other.height;
}

//Pre-increment (++minion)
Minion& Minion::operator++() 
{
    bananasOwned++;
    return *this;
}

//Post-increment (minion++)
Minion Minion::operator++(int) 
{
    Minion temp = *this; // copy before increment
    bananasOwned++;
    return temp;
}

//Static function
void Minion::printMinionCount() 
{
    cout << minionCount << " minions created." << endl;
}

//Friend function
ostream& operator<<(ostream& os, const Minion& m) 
{
    os << "The minion " << m.name << " is " << m.height
       << " inches tall, has " << m.eyes << " eye(s), and owns "
       << m.bananasOwned << " banana(s)." << endl;
    return os;
}

