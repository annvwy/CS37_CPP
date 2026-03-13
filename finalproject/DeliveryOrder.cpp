#include "DeliveryOrder.h"
#include <iomanip>

using namespace std;
// static member definitions
int DeliveryOrder::orderCount = 0;
const double DeliveryOrder::taxRate = 0.09;
const double DeliveryOrder::deliveryRate = 2.0;

DeliveryOrder::DeliveryOrder(const string &name, const string &date, const string &phone, float miles)
    : name(name), date(date), phone(phone), miles(miles), orderBalance(0.0f)
{
    ++orderCount;
}

DeliveryOrder::~DeliveryOrder() {
    cout << "DeliveryOrder destroyed.\n";
}

void DeliveryOrder::receipt() const {
    cout << "Order Detail:" << "\n";
    cout << "\tName: " << name << "\n";
    cout << "\tDate: " << date << "\n";
    cout << "\tPhone: " << phone << "\n";
    cout << "\tOrder Balance: $" << fixed << setprecision(2) << orderBalance << endl;
}

float DeliveryOrder::getTotalBalance() const {
    return static_cast<float>(orderBalance * (1.0 + taxRate) + miles * deliveryRate);
}

int DeliveryOrder::getOrderCount() {
    return orderCount;
}