//
// Created on 10/29/25.
//

#ifndef HERG_CAFE_PAYMENTSTRATEGY_H
#define HERG_CAFE_PAYMENTSTRATEGY_H
#include <memory>
#include <string>

namespace helper {
    // abstract class
    class PaymentStrategy {

    public:
        virtual ~PaymentStrategy() = default;

        virtual std::unique_ptr<std::string> pay(double amount, int table) = 0;
        // yeah, we can have 2^32 tables why not and also use negative numbering
    };
} // helper

#endif //HERG_CAFE_PAYMENTSTRATEGY_H