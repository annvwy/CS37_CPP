#include "FoodOrder.h"
#include <iomanip>

using namespace std;
FoodOrder::FoodOrder(const string &name, const string &date, const string &phone, float miles, const string &restaurantName)
    : DeliveryOrder(name, date, phone, miles), restaurantName(restaurantName), foodCount(0)
{
}

FoodOrder::~FoodOrder() {
    cout << "FoodOrder destroyed.\n";
}

void FoodOrder::receipt() const {
    DeliveryOrder::receipt();
    cout << "\tFood Count: " << foodCount << endl;
}

float FoodOrder::VIPdiscount() const {
    // Based on orderBalance (which does not include tax/delivery)
    if (orderBalance > 50.0f) return 0.8f;
    if (orderBalance > 30.0f) return 0.9f;
    if (orderBalance > 20.0f) return 0.95f;
    return 1.0f;
}

void FoodOrder::addFood(const string &mainCourse, int sides, bool addSoup) {
    // menu prices
    const float priceCauliflower = 15.0f; // Thick Cauliflower Steaks
    const float priceRackLamb = 38.0f;    // Rack of Lamb
    const float priceScottishSalmon = 23.0f; // Organic Scottish Salmon
    const float priceLobsterRisotto = 46.0f; // Grilled Lobster Risotto

    float basePrice = 0.0f;
    bool matched = true;

    if (mainCourse == "Thick Cauliflower Steaks") {
        basePrice = priceCauliflower;
    } else if (mainCourse == "Rack of Lamb") {
        basePrice = priceRackLamb;
    } else if (mainCourse == "Organic Scottish Salmon") {
        basePrice = priceScottishSalmon;
    } else if (mainCourse == "Grilled Lobster Risotto") {
        basePrice = priceLobsterRisotto;
    } else {
        matched = false;
    }

    if (!matched) {
        throw InvalidInput(mainCourse);
    }

    const float soupPrice = 5.0f;
    const float sidePrice = 6.0f;

    float totalCost = basePrice + sides * sidePrice + (addSoup ? soupPrice : 0.0f);

    // update counters and balance
    foodCount += 1;
    orderBalance += totalCost;
}