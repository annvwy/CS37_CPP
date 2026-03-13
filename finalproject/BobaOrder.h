#ifndef BOBAORDER_H
#define BOBAORDER_H

#include "DeliveryOrder.h"
#include "InvalidInput.h"
#include <string>

using namespace std;
class BobaOrder : public DeliveryOrder {
public:
    BobaOrder(const string &name, const string &date, const string &phone, float miles, const string &shopName);

    ~BobaOrder() override;

    void receipt() const override;

    float VIPdiscount() const override;

    // addDrink: drinkName, addBoba default true, count default 1
    void addDrink(const string &drinkName, bool addBoba = true, int count = 1);

private:
    string shopName;
    int drinksCount;
};

#endif // BOBAORDER_H