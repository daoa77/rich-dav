#ifndef ORDER_H
#define ORDER_H

#include <string>
#include "orderstatus.h"

class Order {
public:
    Order(const std::string& dish);
    std::string getDish() const;
    std::string getStatus() const;
    void updateStatus(OrderStatus::Status newStatus);

private:
    std::string dish;
    OrderStatus status;
};

#endif
