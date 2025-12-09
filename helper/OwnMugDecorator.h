//
// Created on 12/9/25.
//

#ifndef HERGESEL_CAFE_OWNMUGDECORATOR_H
#define HERGESEL_CAFE_OWNMUGDECORATOR_H
#include "CustomDrinkDecorator.h"

namespace helper {
    class OwnMugDecorator final : public CustomDrinkDecorator {
    public:
        explicit OwnMugDecorator(CustomDrink& drink)
            : CustomDrinkDecorator(drink) {}

        std::string toString() const override {
            return CustomDrinkDecorator::toString() + " [own mug]";
        }
    };
} // helper

#endif //HERGESEL_CAFE_OWNMUGDECORATOR_H