#include "waiter.h"

void Waiter::takeOrder(Customer& customer, const std::string& order, Kitchen& kitchen, Order& orderStatus) {
    std::cout << "Waiter takes order from " << customer.getName() << ": " << order << std::endl;
    customer.placeOrder(order);
    orderStatus.updateStatus(OrderStatus::IN_PROGRESS);
    kitchen.prepareOrder(order);
    orderStatus.updateStatus(OrderStatus::READY);
}

void Waiter::serveOrder(Customer& customer, Kitchen& kitchen, Order& orderStatus) {
    if (kitchen.isOrderReady()) {
        std::cout << "Waiter serves order to " << customer.getName() << std::endl;
        orderStatus.updateStatus(OrderStatus::SERVED);
    } else {
        std::cout << "Order is not ready yet!" << std::endl;
    }
}
