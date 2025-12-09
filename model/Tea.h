//
// Created on 10/22/25.
//

#ifndef HERG_CAFE_TEA_H
#define HERG_CAFE_TEA_H
#include "DrinkTemplate.h"
#include "IDrink.h"

// final with classes: prevents further inheritance
// final with methods: prevents overriding in derived classes
class Tea final: public IDrink, public model::DrinkTemplate {

public:
    std::string_view serve() const override;
    Tea() : DrinkTemplate("Tea") {}
protected:
    void brew() override {
        std::cout << "[APP] Steeping tea bag\n";
    }
};


#endif //HERG_CAFE_TEA_H