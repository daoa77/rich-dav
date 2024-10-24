#include "customer.h"

Customer::Customer(const std::string& name) : name(name), order("") {}

std::string Customer::getName() const {
    return name;
}

void Customer::placeOrder(const std::string& order) {
    this->order = order;
}

std::string Customer::getOrder() const {
    return order;
}
