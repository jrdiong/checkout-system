#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int choice, quantity;
    double price = 0.0, subtotal = 0.0;

    cout << fixed << setprecision(2);

    cout << "\n===== SIMPLE STORE CHECKOUT SYSTEM =====\n";
    cout << "1. Rice (5kg)        RM35\n";
    cout << "2. Cooking Oil (2L)  RM18\n";
    cout << "3. Milk (1L)         RM6\n";
    cout << "4. Bread             RM4\n";
    cout << "5. Eggs (10 pcs)     RM8\n";
    cout << "6. Instant Noodles   RM5\n";
    cout << "Select product (1-6): ";
    cin >> choice;

    if (choice == 1) price = 35;
    else if (choice == 2) price = 18;
    else if (choice == 3) price = 6;
    else if (choice == 4) price = 4;
    else if (choice == 5) price = 8;
    else if (choice == 6) price = 5;
    else {
        cout << "Invalid choice!\n";
        return 0;
    }

    cout << "Enter quantity: ";
    cin >> quantity;

    subtotal = price * quantity;
    cout << "Subtotal: RM " << subtotal << endl;

    return 0;
}
