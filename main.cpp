#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int choice, quantity;
    double price = 0.0, subtotal = 0.0, discount = 0.0, sst, total;
    string promoCode;
    char addMore;

    vector<string> items;
    vector<int> qty;
    vector<double> itemTotal;

    cout << fixed << setprecision(2);

    do {
        cout << "\n===== SIMPLE STORE CHECKOUT SYSTEM =====\n";
        cout << "1. Rice (5kg)        RM35\n";
        cout << "2. Cooking Oil (2L)  RM18\n";
        cout << "3. Milk (1L)         RM6\n";
        cout << "4. Bread             RM4\n";
        cout << "5. Eggs (10 pcs)     RM8\n";
        cout << "6. Instant Noodles   RM5\n";
        cout << "Select product (1-6): ";
        cin >> choice;

        if (choice == 1) {
            price = 35;
            items.push_back("Rice (5kg)");
        }
        else if (choice == 2) {
            price = 18;
            items.push_back("Cooking Oil (2L)");
        }
        else if (choice == 3) {
            price = 6;
            items.push_back("Milk (1L)");
        }
        else if (choice == 4) {
            price = 4;
            items.push_back("Bread");
        }
        else if (choice == 5) {
            price = 8;
            items.push_back("Eggs (10 pcs)");
        }
        else if (choice == 6) {
            price = 5;
            items.push_back("Instant Noodles");
        }
        else {
            cout << "Invalid choice!\n";
            continue;
        }

        cout << "Enter quantity: ";
        cin >> quantity;

        qty.push_back(quantity);
        itemTotal.push_back(price * quantity);

        subtotal += price * quantity;

        cout << "Add another item? (y/n): ";
        cin >> addMore;

    } while (addMore == 'y' || addMore == 'Y');

    // Apply promo code
    cout << "Enter promo code (SAVE10/SAVE20/NONE): ";
    cin >> promoCode;

    if (promoCode == "SAVE10") {
        discount = 0.10 * subtotal;
    } else if (promoCode == "SAVE20") {
        discount = 0.20 * subtotal;
    } else {
        discount = 0.0;
    }

    double afterDiscount = subtotal - discount;

    // Apply SST 6%
    sst = 0.06 * afterDiscount;
    total = afterDiscount + sst;

    // Print receipt
    cout << "\n--------------------- ORDER SUMMARY ---------------------\n";
    cout << left << setw(20) << "Item"
         << right << setw(5) << "Qty"
         << right << setw(15) << "Price(RM)"
         << right << setw(15) << "Total(RM)" << endl;

    cout << "---------------------------------------------------------\n";

    for (int i = 0; i < items.size(); i++) {
        cout << left << setw(20) << items[i]
             << right << setw(5) << qty[i]
             << right << setw(15) << fixed << setprecision(2) << (itemTotal[i] / qty[i])
             << right << setw(15) << fixed << setprecision(2) << itemTotal[i] << endl;
    }

    cout << "---------------------------------------------------------\n";
    cout << right << setw(50) << "Subtotal: RM " << subtotal << endl;
    cout << right << setw(50) << "Discount: RM " << discount << endl;
    cout << right << setw(50) << "SST (6%): RM " << sst << endl;
    cout << right << setw(50) << "Total Payment: RM " << total << endl;

    cout << "\n\t\t\tThank you for shopping with us!\n";
    return 0;
}
