//
// Created on 10/29/25.
//

#include "CashPayment.h"

namespace model {
    std::unique_ptr<std::string> CashPayment::pay(const double amount, const int table) {
        return std::make_unique<std::string>(
                "Customer wants to pay " + std::to_string(amount) + " in cash for table " + std::to_string(table)
        );
    }
}