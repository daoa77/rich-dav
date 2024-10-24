#ifndef TABLE_H
#define TABLE_H

#include "customer.h"
#include <vector>

class Table {
public:
    Table(int tableNumber);
    int getTableNumber() const;
    void addCustomer(Customer& customer);
    std::vector<Customer> getCustomers() const;

private:
    int tableNumber;
    std::vector<Customer> customers;
};

#endif
