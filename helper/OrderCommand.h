//
// Created on 12/6/25.
//

#ifndef HERG_CAFE_ORDERCOMMAND_H
#define HERG_CAFE_ORDERCOMMAND_H
#include <string>

#include "ICommand.h"
#include "OrderSubject.h"

namespace command {
    class OrderCommand final : public ICommand {

    public:
        OrderCommand(OrderSubject &orderSubject, std::string info)
                : orderSubject_(orderSubject), info_(std::move(info)) {}

        void execute() override {
            // Tady proběhne notifikace v rámci commandu
            orderSubject_.notifyAll("New order: " + info_);
        }

    private:
        OrderSubject &orderSubject_;
        std::string info_;

    };
}
#endif //HERG_CAFE_ORDERCOMMAND_H