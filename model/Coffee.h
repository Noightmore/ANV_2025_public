//
// Created on 10/22/25.
//

#ifndef HERG_CAFE_COFFEE_H
#define HERG_CAFE_COFFEE_H
#include "DrinkTemplate.h"
#include "IDrink.h"

// final with classes: prevents further inheritance
// final with methods: prevents overriding in derived classes

class Coffee final : public IDrink, public model::DrinkTemplate {
public:
    std::string_view serve() const override;
    Coffee() : DrinkTemplate("Coffee") {}

protected:
    void brew() override {
        std::cout << "[APP] Brewing coffee grounds\n";
    }
};


#endif //HERG_CAFE_COFFEE_H