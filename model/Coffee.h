//
// Created on 10/22/25.
//

#ifndef HERG_CAFE_COFFEE_H
#define HERG_CAFE_COFFEE_H
#include "IDrink.h"

// final with classes: prevents further inheritance
// final with methods: prevents overriding in derived classes

class Coffee final : public IDrink {

    std::string_view serve() const override;
};


#endif //HERG_CAFE_COFFEE_H