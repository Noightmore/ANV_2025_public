//
// Created  on 12/6/25.
//

#ifndef HER_CAFE_PAYMENTCOMMAND_H
#define HERG_CAFE_PAYMENTCOMMAND_H
#include "Checkout.h"
#include "ICommand.h"
#include "OrderSubject.h"

namespace command {
    class PaymentCommand final : public ICommand {
    public:
        PaymentCommand(OrderSubject &paymentSubject,
                       helper::Checkout &checkout,
                       const double amount,
                       const int tableNumber)
            : paymentSubject_(paymentSubject),
              checkout_(checkout),
              amount_(amount),
              tableNumber_(tableNumber) {}

        void execute() override {
            // 1) provedení platby přes aktuální strategii
            checkout_.processPayment(amount_, tableNumber_);
            // 2) notifikace všech pozorovatelů
            paymentSubject_.notifyAll(
                "Payment of " + std::to_string(amount_) +
                " for table " + std::to_string(tableNumber_)
            );
        }

    private:
        OrderSubject &paymentSubject_;
        helper::Checkout &checkout_;
        double amount_;
        int tableNumber_;
    };
}
#endif //HERG_CAFE_PAYMENTCOMMAND_H