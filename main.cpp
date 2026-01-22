#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int choice;

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

    return 0;
}
