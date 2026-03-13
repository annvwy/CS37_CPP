#ifndef DELIVERYORDER_H
#define DELIVERYORDER_H

#include <string>
#include <iostream>

using namespace std;
class DeliveryOrder {
public:
    DeliveryOrder(const string &name, const string &date, const string &phone, float miles);

    virtual ~DeliveryOrder();

    // print a receipt (non-modifying)
    virtual void receipt() const;

    // compute total balance: orderBalance with tax + delivery fee
    float getTotalBalance() const;

    // return how many orders were created
    static int getOrderCount();

    // VIP discount - pure virtual; subclasses will implement
    virtual float VIPdiscount() const = 0;

protected:
    // accessible to subclasses
    float orderBalance;

private:
    string name;
    string date;
    string phone;
    float miles;

    static int orderCount;
    static const double taxRate;
    static const double deliveryRate;
};

#endif // DELIVERYORDER_H