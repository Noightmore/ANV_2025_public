#include <iostream>

#include "config/CafeConfig.h"
#include "helper/CustomDrink.h"
#include "helper/DrinkFactory.h"
#include "helper/EmployeeObserver.h"
#include "helper/OrderSubject.h"

int main() {
    //CafeConfig& config = CafeConfig::getInstance();
    //CafeConfig& config2 = CafeConfig::getInstance(); // should return the same instance

    std::cout << DrinkFactory::createDrink("Tea").serve() << " in "
           << CafeConfig::getInstance().getCafeName() << '\n';
    std::cout << DrinkFactory::createDrink("Coffee").serve() << " in "
           << CafeConfig::getInstance().getCafeName() << '\n';

    std::cout << CustomDrink::Builder("Coffee").withSugar().withCaramel().build().toString()  << std::endl;

    auto order_subject = OrderSubject();
    order_subject.addObserver(new EmployeeObserver("Barista"));
    order_subject.addObserver(new EmployeeObserver("Sexista"));

    const auto new_custom_drink = CustomDrink::Builder("Tea").withMilk().withSugar().build();

    const auto message = "New order: " + new_custom_drink.toString() + " in "
                        + std::string(CafeConfig::getInstance().getCafeName());

    std::cout << message << '\n';

    order_subject.notifyAll(message);

    return 0;
}
