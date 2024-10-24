#include "kitchen.h"
#include <iostream>

void Kitchen::prepareOrder(const std::string& order) {
    currentOrder = order;
    std::cout << "Preparing order: " << order << std::endl;
    orderReady = true; // Simulasi bahwa order langsung jadi
}

bool Kitchen::isOrderReady() const {
    return orderReady;
}
