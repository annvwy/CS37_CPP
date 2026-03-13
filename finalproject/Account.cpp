#include "Account.h"

using namespace std;
Account::Account(const string &username, const string &status)
    : username(username), status(status)
{
}

Account::~Account() {
    cout << "Account removed.\n";
}

string Account::getStatus() const {
    return status;
}