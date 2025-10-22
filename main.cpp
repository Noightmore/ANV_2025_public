#include <iostream>

#include "config/CafeConfig.h"
#include "model/DrinkFactory.h"

int main() {
    //CafeConfig& config = CafeConfig::getInstance();
    //CafeConfig& config2 = CafeConfig::getInstance(); // should return the same instance

    std::cout << DrinkFactory::createDrink("Tea").serve() << " in "
           << CafeConfig::getInstance().getCafeName() << std::endl;
    std::cout << DrinkFactory::createDrink("Coffee").serve() << " in "
           << CafeConfig::getInstance().getCafeName() << std::endl;
    return 0;
}
