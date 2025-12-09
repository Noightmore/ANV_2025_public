#include <iostream>
#include "config/CafeConfig.h"
#include "helper/Checkout.h"
#include "helper/CustomDrink.h"
#include "helper/DrinkFactory.h"
#include "helper/EmployeeObserver.h"
#include "helper/OrderCommand.h"
#include "helper/OrderSubject.h"
#include "helper/OwnMugDecorator.h"
#include "helper/PaymentCommand.h"
#include "helper/ToGoDecorator.h"
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


    // STRATEGY

    // stack allocation:
    /*auto order = OrderSubject();
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
    payment.notifyAll(*checkout.processPayment(15,42));*/


    // -----------------------------------------
    // OBSERVER + COMMAND + STRATEGY část
    // -----------------------------------------

    /*
    // Subjekt pro objednávky
    auto orderSubject = OrderSubject();

    // Subjekt pro platby
    auto paymentSubject = OrderSubject();

    // Zaměstnanci (pozorovatelé)
    auto waiter  = EmployeeObserver("Waiter");
    auto barista = EmployeeObserver("Barista");

    // Kdo reaguje na objednávky
    orderSubject.addObserver(&barista);
    orderSubject.addObserver(&waiter);

    // Kdo reaguje na platby
    paymentSubject.addObserver(&waiter);

    // Vytvoříme vlastní drink
    const auto customDrink =
        CustomDrink::Builder("Tea").withMilk().withSugar().build();

    const auto cafeName = std::string(CafeConfig::getInstance().getCafeName());

    // --- ORDER COMMANDS ---

    const auto orderMessage =
        "New order: " + customDrink.toString() + " in " + cafeName;

    command::OrderCommand teaOrder(orderSubject, orderMessage);

    // Pokud máš více objednávek, prostě vytvoříš další Command:
    const auto coffeeDrink =
        CustomDrink::Builder("Coffee").withMilk().withSugar().build();
    const auto coffeeOrderMessage =
        "New order: " + coffeeDrink.toString() + " in " + cafeName;

    command::OrderCommand coffeeOrder(orderSubject, coffeeOrderMessage);

    // Spuštění commandů (notifikace proběhnou uvnitř execute())
    teaOrder.execute();
    coffeeOrder.execute();

    // --- PAYMENT COMMANDS (STRATEGY + COMMAND) ---

    auto checkout = helper::Checkout(std::make_unique<model::CreditCardPayment>());

    // Zaplacení kartou
    command::PaymentCommand payByCard(
        paymentSubject,   // payment subject
        checkout,  // checkout se strategií CreditCardPayment
        20.0,      // amount
        -234566    // table number
    );

    payByCard.execute();

    // Změna strategie na cash
    checkout.setPaymentStrategy(std::make_unique<model::CashPayment>());

    command::PaymentCommand payByCash(
        paymentSubject,
        checkout,
        15.0,
        42
    );

    payByCash.execute();
    */

    // -----------------------------------------
    // OBSERVER + COMMAND + STRATEGY část
    // -----------------------------------------

    // Subjekt pro objednávky
    auto orderSubject = OrderSubject();

    // Subjekt pro platby
    auto paymentSubject = OrderSubject();

    // Zaměstnanci (pozorovatelé)
    auto waiter  = EmployeeObserver("Waiter");
    auto barista = EmployeeObserver("Barista");

    // Kdo reaguje na objednávky
    orderSubject.addObserver(&barista);
    orderSubject.addObserver(&waiter);

    // Kdo reaguje na platby
    paymentSubject.addObserver(&waiter);

    const auto cafeName = std::string(CafeConfig::getInstance().getCafeName());

    // ----------- DRINKS + DECORATORS -----------

    // Tea: milk + sugar, to-go + own mug (example)
    CustomDrink baseTea =
        CustomDrink::Builder("Tea").withMilk().withSugar().build();

    // chain decorators: ToGo -> OwnMug
    helper::ToGoDecorator      teaToGo(baseTea);
    helper::OwnMugDecorator    teaOwnMug(teaToGo);

    // Coffee: milk + sugar, only own mug (example)
    CustomDrink baseCoffee =
        CustomDrink::Builder("Coffee").withMilk().build();

    helper::OwnMugDecorator    coffeeOwnMug(baseCoffee);

    // --- ORDER COMMANDS ---

    const auto teaOrderMessage =
        "New order: " + teaOwnMug.toString() + " in " + cafeName;

    command::OrderCommand teaOrder(orderSubject, teaOrderMessage);

    const auto coffeeOrderMessage =
        "New order: " + coffeeOwnMug.toString() + " in " + cafeName;

    command::OrderCommand coffeeOrder(orderSubject, coffeeOrderMessage);

    // Spuštění commandů (notifikace proběhnou uvnitř execute())
    teaOrder.execute();
    coffeeOrder.execute();

    // --- PAYMENT COMMANDS (STRATEGY + COMMAND) ---

    auto checkout = helper::Checkout(std::make_unique<model::CreditCardPayment>());

    // Zaplacení kartou
    command::PaymentCommand payByCard(
        paymentSubject,   // payment subject
        checkout,         // checkout se strategií CreditCardPayment
        20.0,             // amount
        -234566           // table number
    );
    payByCard.execute();

    // Změna strategie na cash
    checkout.setPaymentStrategy(std::make_unique<model::CashPayment>());

    command::PaymentCommand payByCash(
        paymentSubject,
        checkout,
        15.0,
        42
    );
    payByCash.execute();

    return 0;

}
