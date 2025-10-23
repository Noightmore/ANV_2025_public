//
// Created on 10/22/25.
//

#ifndef HERG_CAFE_DRINKFACTORY_H
#define HERG_CAFE_DRINKFACTORY_H
#include "../model/IDrink.h"

enum class DrinkType {
    Coffee,
    Tea,
    UNKNOWN
};

class DrinkFactory final{

public:
    static DrinkType stringToCoffeeType(std::string_view str);
    static IDrink& createDrink(std::string_view  drink_type);
};


#endif //HERG_CAFE_DRINKFACTORY_H