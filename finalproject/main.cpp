#include <iostream>
#include <iomanip>
#include "InvalidInput.h"
#include "DeliveryOrder.h"
#include "BobaOrder.h"
#include "FoodOrder.h"
#include "Account.h"

using namespace std;
// applyDiscount: returns the final balance after applying account-based multiplier
float applyDiscount(DeliveryOrder *order, const Account &account) {
    float total = order->getTotalBalance();
    string status = account.getStatus();

    if (status == "Owner") {
        // Owner pays 10% of total (90% off)
        return total * 0.1f;
    } else if (status == "VIP") {
        // dynamic binding to call the correct VIPdiscount
        float mult = order->VIPdiscount();
        return total * mult;
    } else {
        // Regular
        return total;
    }
}

int main() {
    cout << fixed << setprecision(2);

    // create accounts (Stuart is owner, Kevin VIP, Bob regular)
    const Account stuartAccount("Stuart", "Owner");
    Account kevinAccount("Kevin", "VIP");
    Account bobAccount("Bob"); // default Regular

    // DeliveryOrder pointer for polymorphism (can be nullptr initially)
    DeliveryOrder *dptr = nullptr;

    // 1. Kevin placing order
    cout << "Kevin is placing order.\n";

    BobaOrder kevinOrder("Kevin", "04/20/2024", "123-456-0000", 10.4f, "M Tea");

    try {
        kevinOrder.addDrink("Green Tea Latte");                  // default: add boba, count 1
        kevinOrder.addDrink("Brown Sugar Pearl Milk", false);   // no boba, count 1
        kevinOrder.addDrink("Brown Sugar Boba Milk", false, 2); // no boba, count 2
        // invalid drink
        kevinOrder.addDrink("Iron Goddess");
    } catch (InvalidInput &e) {
        e.reason();
        cout << "\nNot serving requested drinks. Drink order ignored.\n\n";
    }

    kevinOrder.receipt();
    cout << "Balance: $" << kevinOrder.getTotalBalance() << "\n";

    dptr = &kevinOrder;
    cout << "Discounted Balance: $" << applyDiscount(dptr, kevinAccount) << "\n\n\n";

    // 2. Stuart placing order
    cout << "Stuart is placing order.\n";

    FoodOrder stuartOrder("Stuart", "04/20/2024", "123-456-1111", 25.5f, "Tavern Green");

    try {
        stuartOrder.addFood("Thick Cauliflower Steaks", 1, true); // one side, one soup
        stuartOrder.addFood("Organic Scottish Salmon", 0, false);
        stuartOrder.addFood("Rack of Lamb", 0, true); // one soup, no sides
    } catch (InvalidInput &e) {
        e.reason();
        cout << "\nNot serving requested food. Food order ignored.\n\n";
    }

    stuartOrder.receipt();
    cout << "Balance: $" << stuartOrder.getTotalBalance() << "\n";

    dptr = &stuartOrder;
    cout << "Discounted Balance: $" << applyDiscount(dptr, stuartAccount) << "\n\n\n";

    // 3. Bob placing order (uses Stuart's order object)
    cout << "Bob decided to log in to his account and see whether he can afford ordering the same order as Stuart.\n";

    // print the same receipt (stuart's)
    stuartOrder.receipt();
    cout << "Balance: $" << stuartOrder.getTotalBalance() << "\n";

    dptr = &stuartOrder;
    cout << "Discounted Balance: $" << applyDiscount(dptr, bobAccount) << "\n";

    cout << "Bob upset, cancelling order :(\n\n";

    // total orders placed
    cout << "Total order placed: " << DeliveryOrder::getOrderCount() << "\n\n";

    // end main: destructors will run in reverse order of creation
    return 0;
}