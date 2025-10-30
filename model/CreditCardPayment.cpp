//
// Created on 10/29/25.
//

#include "CreditCardPayment.h"

namespace model {

    std::unique_ptr<std::string> CreditCardPayment::pay(const double amount, const int table) {
        return std::make_unique<std::string>(
                "Customer wants to pay " + std::to_string(amount) + " for table " + std::to_string(table)
                + " using Credit Card.");
    }

} // model