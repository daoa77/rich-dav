#ifndef WAITER_H
#define WAITER_H

#include "customer.h"
#include "kitchen.h"
#include "order.h"
#include <iostream>

class Waiter {
public:
    void takeOrder(Customer& customer, const std::string& order, Kitchen& kitchen, Order& orderStatus);
    void serveOrder(Customer& customer, Kitchen& kitchen, Order& orderStatus);
};

#endif
