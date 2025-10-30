//
// Created on 10/29/25.
//

#ifndef HERG_CAFE_CREDITCARDPAYMENT_H
#define HERG_CAFE_CREDITCARDPAYMENT_H
#include "../helper/PaymentStrategy.h"

namespace model {
    class CreditCardPayment final : public helper::PaymentStrategy {

    public:
        std::unique_ptr<std::string> pay(double amount, int table) override;
    };
} // model

#endif //HERG_CAFE_CREDITCARDPAYMENT_H