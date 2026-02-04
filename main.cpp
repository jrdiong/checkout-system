#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

double getPrice(int choice, string &itemName) {
    switch(choice) {
        case 1: itemName = "Rice (5kg)"; return 35;
        case 2: itemName = "Cooking Oil (2L)"; return 18;
        case 3: itemName = "Milk (1L)"; return 6;
        case 4: itemName = "Bread"; return 4;
        case 5: itemName = "Eggs (10 pcs)"; return 8;
        case 6: itemName = "Instant Noodles"; return 5;
        default: return 0;
    }
}

int main()
{
    int choice, quantity;
    double price = 0.0, subtotal = 0.0, discount = 0.0, sst, total;
    string promoCode, itemName;
    char addMore;

    vector<string> items;
    vector<int> qty;
    vector<double> itemTotal;

    cout << fixed << setprecision(2);

    do
    {
        cout << "\n===== SIMPLE STORE CHECKOUT SYSTEM =====\n";
        cout << "1. Rice (5kg)        RM35\n";
        cout << "2. Cooking Oil (2L)  RM18\n";
        cout << "3. Milk (1L)         RM6\n";
        cout << "4. Bread             RM4\n";
        cout << "5. Eggs (10 pcs)     RM8\n";
        cout << "6. Instant Noodles   RM5\n";
        cout << "Select product (1-6): ";
        cin >> choice;

        price = getPrice(choice, itemName);
        if(price == 0) {
            cout << "Invalid choice!\n";
            continue;
        }
        items.push_back(itemName);

        do
        {
            cout << "Enter quantity: ";
            cin >> quantity;

            if (quantity <= 0)
            {
                cout << "Invalid quantity! Please enter a positive number.\n";
            }
        } while (quantity <= 0);

        qty.push_back(quantity);
        itemTotal.push_back(price * quantity);

        subtotal += price * quantity;

        cout << "Add another item? (y/n): ";
        cin >> addMore;

    } while (addMore == 'y' || addMore == 'Y');

    // Apply promo code
    do {
        cout << "Enter promo code (SAVE10/SAVE20/NONE): ";
        cin >> promoCode;

        if(promoCode != "SAVE10" && promoCode != "SAVE20" && promoCode != "NONE"){
            cout << "Invalid promo code! Enter again.\n";
        }
    } while(promoCode != "SAVE10" && promoCode != "SAVE20" && promoCode != "NONE");

    if (promoCode == "SAVE10")
    {
        discount = 0.10 * subtotal;
    }
    else if (promoCode == "SAVE20")
    {
        discount = 0.20 * subtotal;
    }
    else
    {
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

    for (int i = 0; i < items.size(); i++)
    {
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

