#ifndef ORDERSTATUS_H
#define ORDERSTATUS_H

#include <string>

class OrderStatus {
public:
    enum Status { RECEIVED, IN_PROGRESS, READY, SERVED };
    OrderStatus();
    void updateStatus(Status newStatus);
    std::string getStatus() const;

private:
    Status status;
};

#endif
