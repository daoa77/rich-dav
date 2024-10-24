#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>
#include "customer.h"
#include "kitchen.h"
#include "waiter.h"
#include "table.h"
#include "order.h"

class GameManager {
public:
    GameManager();
    void addCustomer(const std::string& name);
    void takeOrder(int tableNumber, const std::string& dish);
    void serveOrder(int tableNumber);
    void update();
    void displayStatus() const;

private:
    std::vector<Table> tables;
    Kitchen kitchen;
    Waiter waiter;
    std::vector<Order> orders;
};

#endif
