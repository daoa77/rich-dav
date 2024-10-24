#include "table.h"

Table::Table(int tableNumber) : tableNumber(tableNumber) {}

int Table::getTableNumber() const {
    return tableNumber;
}

void Table::addCustomer(Customer& customer) {
    customers.push_back(customer);
}

std::vector<Customer> Table::getCustomers() const {
    return customers;
}
