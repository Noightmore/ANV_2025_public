//
// Created by rob on 10/30/25.
//

#include "Checkout.h"

namespace helper {
    void Checkout::setPaymentStrategy(std::unique_ptr<PaymentStrategy>&& obj) {
        obj_ = std::move(obj);
    }

    std::unique_ptr<std::string>  Checkout::processPayment(const double amount, const int table) const {
        auto receipt = obj_->pay(amount, table);
        return std::move(receipt);
    }
} // helper