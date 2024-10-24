#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
public:
    Customer(const std::string& name);
    std::string getName() const;
    void placeOrder(const std::string& order);
    std::string getOrder() const;

private:
    std::string name;
    std::string order;
};

#endif