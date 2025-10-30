#include <iostream>

#include "config/CafeConfig.h"
#include "helper/Checkout.h"
#include "helper/CustomDrink.h"
#include "helper/DrinkFactory.h"
#include "helper/EmployeeObserver.h"
#include "helper/OrderSubject.h"
#include "model/CashPayment.h"
#include "model/CreditCardPayment.h"

int main() {
    //CafeConfig& config = CafeConfig::getInstance();
    //CafeConfig& config2 = CafeConfig::getInstance(); // should return the same instance

    /*
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
    */
    // prvni 4 navrhove vzory


    // stack allocation:
    auto order = OrderSubject();
    // heap allocation:
    // auto order = new OrderSubject();

    auto waiter = EmployeeObserver("Waiter");
    auto barista = EmployeeObserver("Barista");

    order.addObserver(&barista);
    order.addObserver(&waiter);

    const auto customDrink = CustomDrink::Builder("Coffee").withMilk().withSugar().build();

    order.notifyAll(customDrink.toString() + " in " + std::string(CafeConfig::getInstance().getCafeName()));

    auto payment = OrderSubject();
    payment.addObserver(&waiter);

    auto checkout = helper::Checkout(std::make_unique<model::CreditCardPayment>());
    payment.notifyAll(*checkout.processPayment(20,-234566));
    checkout.setPaymentStrategy(std::make_unique<model::CashPayment>());
    payment.notifyAll(*checkout.processPayment(15,42));

    return 0;
}
