#include "order.h"

Order::Order(const std::string& dish) : dish(dish), status() {}

std::string Order::getDish() const {
    return dish;
}

std::string Order::getStatus() const {
    return status.getStatus();
}

void Order::updateStatus(OrderStatus::Status newStatus) {
    status.updateStatus(newStatus);
}
