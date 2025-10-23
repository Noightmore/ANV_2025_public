//
// Created on 10/22/25.
//

#include "CustomDrink.h"
#include "DrinkFactory.h"  // Assuming you have this

std::string CustomDrink::toString() const {

    auto result = std::string(DrinkFactory::createDrink(this->base).serve())
                    + (milk ? " + Milk" : "")
                    + (sugar ? " + Sugar" : "")
                    + (caramel ? " + Caramel" : "");
                    // condition is NOT always false!!!!

    return result;
}