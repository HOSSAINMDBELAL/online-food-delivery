#include <iostream>
#include <string>
#include <thread>
#include <chrono>   // for sleep
#include <cstdlib>  // for rand
#include <ctime>    // for seeding rand
using namespace std;

int main() {
    srand(time(0)); // Seed random for order number
    int orderNumber = 1000 + rand() % 9000; // Random 4-digit order number

    int choice, quantity, paymentChoice;
    double distance, price, deliveryFee, subtotal = 0, discount = 0, total;
    string food, paymentMethod, address;

    cout << "=== Food Delivery System ===\n";
    cout << "Your Order Number: #" << orderNumber << "\n";

    cout << "\nEnter your delivery address: ";
    cin.ignore(); // clear buffer
    getline(cin, address);

    cout << "\nMenu:\n";
    cout << "1. Burger (RM10)\n";
    cout << "2. Pizza (RM15)\n";
    cout << "3. Salad (RM8)\n";
    cout << "0. Finish Order\n";

    // Ordering multiple items
    while (true) {
        cout << "\nEnter your choice (1-3, 0 to finish): ";
        cin >> choice;

        if (choice == 0) break; // Stop ordering

        cout << "Enter quantity: ";
        cin >> quantity;

        switch (choice) {
            case 1:
                food = "Burger";
                price = 10 * quantity;
                break;
            case 2:
                food = "Pizza";
                price = 15 * quantity;
                break;
            case 3:
                food = "Salad";
                price = 8 * quantity;
                break;
            default:
                cout << "Invalid choice!";
                continue;
        }

        cout << quantity << " x " << food << " added! (Subtotal: RM" << price << ")\n";
        subtotal += price;
    }

    // Apply discount if subtotal > RM50
    if (subtotal > 50) {
        discount = subtotal * 0.10; // 10% discount
        subtotal -= discount;
    }

    cout << "\nEnter delivery distance (in km): ";
    cin >> distance;

    // Delivery fee = RM2 per km
    deliveryFee = distance * 2;
    total = subtotal + deliveryFee;

    // Payment selection
    cout << "\nSelect Payment Method:\n";
    cout << "1. Cash on Delivery\n";
    cout << "2. Credit Card\n";
    cout << "3. E-Wallet\n";
    cout << "Enter your choice (1-3): ";
    cin >> paymentChoice;

    switch (paymentChoice) {
        case 1:
            paymentMethod = "Cash on Delivery";
            break;
        case 2:
            paymentMethod = "Credit Card";
            break;
        case 3:
            paymentMethod = "E-Wallet";
            break;
        default:
            paymentMethod = "Unknown";
    }

    // Final order summary
    cout << "\n=== Order Summary ===\n";
    cout << "Order Number: #" << orderNumber << endl;
    cout << "Delivery Address: " << address << endl;
    cout << "Food Price (before discount): RM" << (subtotal + discount) << endl;
    if (discount > 0) {
        cout << "Discount (10%): -RM" << discount << endl;
    }
    cout << "Food Price (after discount): RM" << subtotal << endl;
    cout << "Delivery Fee: RM" << deliveryFee << endl;
    cout << "Final Total: RM" << total << endl;
    cout << "Payment Method: " << paymentMethod << endl;

    // Order tracking simulation
    cout << "\n=== Order Tracking ===\n";
    cout << "Preparing your order...\n";
    this_thread::sleep_for(chrono::seconds(2)); // simulate delay

    cout << "Order is on the way...\n";
    this_thread::sleep_for(chrono::seconds(2)); // simulate delay

    cout << "Order has been delivered to " << address << "! Enjoy your meal :)\n";

    return 0;
}
