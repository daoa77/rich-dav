#include "gamemanager.h"
#include <iostream>

GameManager::GameManager() {
    // Initialize tables (example: create 5 tables)
    for (int i = 1; i <= 5; ++i) {
        tables.emplace_back(i);
    }
}

void GameManager::addCustomer(const std::string& name) {
    for (auto& table : tables) {
        if (table.getCustomers().empty()) {
            Customer newCustomer(name);
            table.addCustomer(newCustomer);
            std::cout << "Customer " << name << " seated at table " << table.getTableNumber() << std::endl;
            return;
        }
    }
    std::cout << "No available tables for customer " << name << std::endl;
}

void GameManager::takeOrder(int tableNumber, const std::string& dish) {
    for (auto& table : tables) {
        if (table.getTableNumber() == tableNumber) {
            auto customers = table.getCustomers();
            if (!customers.empty()) {
                Customer& customer = customers.front();
                Order newOrder(dish);
                orders.push_back(newOrder);
                waiter.takeOrder(customer, dish, kitchen, newOrder);
                std::cout << "Order taken for " << dish << " at table " << tableNumber << std::endl;
            }
            return;
        }
    }
    std::cout << "Table " << tableNumber << " not found" << std::endl;
}

void GameManager::serveOrder(int tableNumber) {
    for (auto& table : tables) {
        if (table.getTableNumber() == tableNumber) {
            auto customers = table.getCustomers();
            if (!customers.empty() && !orders.empty()) {
                Customer& customer = customers.front();
                Order& order = orders.front();
                waiter.serveOrder(customer, kitchen, order);
                std::cout << "Order served at table " << tableNumber << std::endl;
                orders.erase(orders.begin());  // Remove the served order
            }
            return;
        }
    }
    std::cout << "Table " << tableNumber << " not found" << std::endl;
}

void GameManager::update() {
    std::cout << "Updating game state..." << std::endl;
}

void GameManager::displayStatus() const {
    std::cout << "Current restaurant status:" << std::endl;
    for (const auto& table : tables) {
        std::cout << "Table " << table.getTableNumber() << ": ";
        auto customers = table.getCustomers();
        if (!customers.empty()) {
            std::cout << "Customer: " << customers.front().getName() << std::endl;
        } else {
            std::cout << "Empty" << std::endl;
        }
    }
}
