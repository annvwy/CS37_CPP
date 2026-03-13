#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>

using namespace std;
class Account {
public:
    // status defaults to "Regular"
    explicit Account(const string &username, const string &status = "Regular");

    ~Account();

    string getStatus() const;

private:
    string username;
    string status;
};

#endif // ACCOUNT_H