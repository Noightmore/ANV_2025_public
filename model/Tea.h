//
// Created on 10/22/25.
//

#ifndef HERG_CAFE_TEA_H
#define HERG_CAFE_TEA_H
#include "IDrink.h"

// final with classes: prevents further inheritance
// final with methods: prevents overriding in derived classes
class Tea final: public IDrink {

    std::string_view serve() const override;
};


#endif //HERG_CAFE_TEA_H