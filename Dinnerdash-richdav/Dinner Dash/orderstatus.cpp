#include "orderstatus.h"

OrderStatus::OrderStatus() : status(RECEIVED) {}

void OrderStatus::updateStatus(Status newStatus) {
    status = newStatus;
}

std::string OrderStatus::getStatus() const {
    switch (status) {
        case RECEIVED: return "Received";
        case IN_PROGRESS: return "In Progress";
        case READY: return "Ready";
        case SERVED: return "Served";
        default: return "Unknown";
    }
}
