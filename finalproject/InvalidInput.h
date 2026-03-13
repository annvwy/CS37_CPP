#ifndef INVALIDINPUT_H
#define INVALIDINPUT_H

#include <string>
#include <iostream>

using namespace std;
class InvalidInput {
public:
    // initialize message using initialization list
    explicit InvalidInput(const string &input) : message("Invalid input \"" + input + "\".\n") {}

    // output the message
    void reason() const {
        cout << message;
    }

private:
    const string message;
};

#endif // INVALIDINPUT_H