#ifndef KITCHEN_H
#define KITCHEN_H

#include <string>

class Kitchen {
public:
    void prepareOrder(const std::string& order);
    bool isOrderReady() const;

private:
    std::string currentOrder;
    bool orderReady = false;
};

#endif