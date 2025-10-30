//
// Created on 10/30/25.
//

#ifndef HERG_CAFE_CHECKOUT_H
#define HERG_CAFE_CHECKOUT_H
#include <memory>

#include "PaymentStrategy.h"

namespace helper {
    class Checkout {
    private:
        std::unique_ptr<PaymentStrategy> obj_;

    public :
        explicit Checkout(std::unique_ptr<PaymentStrategy>&& obj) : obj_(std::move(obj)) {}

        ~Checkout() = default;

        void setPaymentStrategy(std::unique_ptr<PaymentStrategy> &&obj);

        std::unique_ptr<std::string> processPayment(double amount, int table) const;
    };
} // helper

#endif //HERG_CAFE_CHECKOUT_H