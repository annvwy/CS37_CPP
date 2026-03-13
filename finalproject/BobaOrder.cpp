#include "BobaOrder.h"
#include <algorithm> // for transform if needed
#include <iomanip>

using namespace std;
BobaOrder::BobaOrder(const string &name, const string &date, const string &phone, float miles, const string &shopName)
    : DeliveryOrder(name, date, phone, miles), shopName(shopName), drinksCount(0)
{
}

BobaOrder::~BobaOrder() {
    cout << "BobaOrder destroyed.\n";
}

void BobaOrder::receipt() const {
    // reuse DeliveryOrder's receipt to stay DRY
    DeliveryOrder::receipt();
    cout << "\tDrinks Count: " << drinksCount << endl;
}

float BobaOrder::VIPdiscount() const {
    if (drinksCount > 10) return 0.8f;
    if (drinksCount > 5)  return 0.9f;
    if (drinksCount > 2)  return 0.95f;
    return 1.0f;
}

void BobaOrder::addDrink(const string &drinkName, bool addBoba, int count) {
    // prices
    const float priceGreenTeaLatte = 5.8f;
    const float priceBrownSugarBobaMilk = 7.8f;
    const float priceBrownSugarPearlMilk = 9.8f;

    float unitPrice = 0.0f;
    bool matched = true;

    if (drinkName == "Green Tea Latte") {
        unitPrice = priceGreenTeaLatte;
    } else if (drinkName == "Brown Sugar Boba Milk") {
        unitPrice = priceBrownSugarBobaMilk;
    } else if (drinkName == "Brown Sugar Pearl Milk") {
        unitPrice = priceBrownSugarPearlMilk;
    } else {
        matched = false;
    }

    if (!matched) {
        throw InvalidInput(drinkName);
    }

    float addBobaPrice = addBoba ? 1.0f : 0.0f;
    float totalCost = (unitPrice + addBobaPrice) * static_cast<float>(count);

    // update counters and balance
    drinksCount += count;
    orderBalance += totalCost;
}