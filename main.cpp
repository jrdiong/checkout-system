#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int choice, quantity;
    double price = 0.0, subtotal = 0.0;
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

        if (choice == 1) { price = 35; items.push_back("Rice"); }
        else if (choice == 2) { price = 18; items.push_back("Cooking Oil"); }
        else if (choice == 3) { price = 6; items.push_back("Milk"); }
        else if (choice == 4) { price = 4; items.push_back("Bread"); }
        else if (choice == 5) { price = 8; items.push_back("Eggs"); }
        else if (choice == 6) { price = 5; items.push_back("Instant Noodles"); }
        else continue;

        cout << "Enter quantity: ";
        cin >> quantity;

        qty.push_back(quantity);
        itemTotal.push_back(price * quantity);
        subtotal += price * quantity;

        cout << "Add another item? (y/n): ";
        cin >> addMore;

    } while (addMore == 'y' || addMore == 'Y');

    cout << "Subtotal: RM " << subtotal << endl;
    return 0;
}
