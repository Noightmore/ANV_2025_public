//
// Created on 12/9/25.
//

#ifndef HERG_CAFE_TOGODECORATOR_H
#define HERG_CAFE_TOGODECORATOR_H

#include "CustomDrinkDecorator.h"

namespace helper {
    class ToGoDecorator final : public CustomDrinkDecorator {
    public:
        explicit ToGoDecorator(CustomDrink& drink)
        : CustomDrinkDecorator(drink) {}

        std::string toString() const override {
            return CustomDrinkDecorator::toString() + " [to-go]";
        }

    };
} // helper

#endif //HERG_CAFE_TOGODECORATOR_H