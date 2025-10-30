//
// Created on 10/29/25.
//

#ifndef HERG_CAFE_CASHPAYMENT_H
#define HERG_CAFE_CASHPAYMENT_H
#include "../helper/PaymentStrategy.h"

namespace model {
    class CashPayment final: public helper::PaymentStrategy {
    public:
        std::unique_ptr<std::string> pay(double amount, int table) override;
    };
}

#endif //HERG_CAFE_CASHPAYMENT_H