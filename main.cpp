#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

// Enum to represent order status
enum class OrderStatus {
    NotYetTaken,
    InKitchen,
    Served
};

// Class to represent a customer
class Customer {
public:
    Customer(int id) : id(id), emotion(5) {}

    int getId() const { return id; }
    int getEmotion() const { return emotion; }
    void setEmotion(int newEmotion) { emotion = newEmotion; }
    void decreaseEmotion() { if (emotion > 1) --emotion; }

private:
    int id;
    int emotion;
};

// Class to represent a table
class Table {
public:
    Table(int id) : id(id), orderStatus(OrderStatus::NotYetTaken), customer(id) {}

    int getId() const { return id; }
    OrderStatus getOrderStatus() const { return orderStatus; }
    void setOrderStatus(OrderStatus status) { orderStatus = status; }
    Customer& getCustomer() { return customer; }  // Provide non-const access
    const Customer& getCustomer() const { return customer; }  // Provide const access

    void displayOrderStatus() const {
        std::cout << "Table " << id << ": ";
        switch (orderStatus) {
            case OrderStatus::NotYetTaken: std::cout << "Order Not Yet Taken\n"; break;
            case OrderStatus::InKitchen: std::cout << "Order In Kitchen\n"; break;
            case OrderStatus::Served: std::cout << "Order Served\n"; break;
        }
    }

private:
    int id;
    OrderStatus orderStatus;
    Customer customer;
};

// Class to represent the kitchen
class Kitchen {
public:
    void receiveOrder(int tableId) {
        std::cout << "Kitchen: Received order from table " << tableId << "\n";
    }

    void notifyOrderReady(int tableId) {
        std::cout << "Kitchen: Order for table " << tableId << " is ready!\n";
    }
};

// Class to represent the waiter
class Waiter {
public:
    Waiter(Kitchen& kitchen) : kitchen(kitchen) {}

    void takeOrder(Table& table) {
        table.setOrderStatus(OrderStatus::InKitchen);
        kitchen.receiveOrder(table.getId());
    }

    void deliverOrder(Table& table) {
        table.setOrderStatus(OrderStatus::Served);
        table.getCustomer().setEmotion(5);
        std::cout << "Waiter: Delivered order to table " << table.getId() << "\n";
    }

    void checkOrders(std::vector<Table>& tables) {
        for (auto& table : tables) {
            if (table.getOrderStatus() == OrderStatus::InKitchen) {
                kitchen.notifyOrderReady(table.getId());
                deliverOrder(table);
            }
        }
    }

private:
    Kitchen& kitchen;
};

int main() {
    Kitchen kitchen;
    Waiter waiter(kitchen);
    std::vector<Table> tables = { Table(1), Table(2), Table(3) };

    while (true) {
        std::cout << "\nRestaurant Management System\n";
        std::cout << "1. Display Order Status\n";
        std::cout << "2. Take Order\n";
        std::cout << "3. Simulate Order Processing\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            // Display all table statuses
            for (const auto& table : tables) {
                table.displayOrderStatus();
                std::cout << "Customer " << table.getCustomer().getId() 
                          << " emotion: " << table.getCustomer().getEmotion() << "\n";
            }
        } else if (choice == 2) {
            // Take an order for a specific table
            std::cout << "Enter table number to take order (1, 2, or 3): ";
            int tableId;
            std::cin >> tableId;
            if (tableId < 1 || tableId > 3) {
                std::cout << "Invalid table number.\n";
            } else {
                waiter.takeOrder(tables[tableId - 1]);
            }
        } else if (choice == 3) {
            // Simulate order processing
            std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate 1 second delay
            for (auto& table : tables) {
                table.getCustomer().decreaseEmotion();
            }
            waiter.checkOrders(tables);
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
