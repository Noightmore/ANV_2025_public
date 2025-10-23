//
// Created by rob on 10/22/25.
//

#include "DrinkFactory.h"

#include <stdexcept>

#include "../model/Coffee.h"
#include "../model/Tea.h"

DrinkType DrinkFactory::stringToCoffeeType(std::string_view const str){
    if (str == "Tea") return DrinkType::Tea;
    if (str == "Coffee") return DrinkType::Coffee;
    return DrinkType::UNKNOWN;
}


IDrink& DrinkFactory::createDrink(std::string_view const drink_type) {
    switch (auto my_drink_type = DrinkFactory::stringToCoffeeType(drink_type)) {
        case DrinkType::Tea:
            {
                static Tea tea_instance;
                return tea_instance;
            }
        case DrinkType::Coffee:
            {
                static Coffee coffee_instance;
                return coffee_instance;
            }

            default:
                throw std::invalid_argument("Unknown drink type");

    }
}
