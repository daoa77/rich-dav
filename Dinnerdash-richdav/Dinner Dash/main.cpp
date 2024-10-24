#include <iostream>
#include "gamemanager.h"

using namespace std;

void displayMenu() {
    cout << "\n=== Dinner Dash Simulation ===\n";
    cout << "1. Add Customer\n";
    cout << "2. Take Order\n";
    cout << "3. Serve Order\n";
    cout << "4. Display Status\n";
    cout << "0. Exit\n";
    cout << "Select an option: ";
}

int main() {
    GameManager gameManager;
    int choice;
    string customerName, dish;
    int tableNumber;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                cin >> customerName;
                gameManager.addCustomer(customerName);
                break;

            case 2:
                cout << "Enter table number: ";
                cin >> tableNumber;
                cout << "Enter dish: ";
                cin >> dish;
                gameManager.takeOrder(tableNumber, dish);
                break;

            case 3:
                cout << "Enter table number to serve: ";
                cin >> tableNumber;
                gameManager.serveOrder(tableNumber);
                break;

            case 4:
                gameManager.displayStatus();
                break;

            case 0:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}