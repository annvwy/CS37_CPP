#ifndef FOODORDER_H
#define FOODORDER_H

#include "DeliveryOrder.h"
#include "InvalidInput.h"
#include <string>

using namespace std;
class FoodOrder : public DeliveryOrder {
public:
    FoodOrder(const string &name, const string &date, const string &phone, float miles, const string &restaurantName);

    ~FoodOrder() override;

    void receipt() const override;

    float VIPdiscount() const override;

    // addFood: mainCourseName, sides default 0, addSoup default false
    void addFood(const string &mainCourse, int sides = 0, bool addSoup = false);

private:
    string restaurantName;
    int foodCount;
};

#endif // FOODORDER_H
