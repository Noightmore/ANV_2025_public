cmake_minimum_required(VERSION 3.25)
project(hergesel_cafe)

set(CMAKE_CXX_STANDARD 23)

add_executable(hergesel_cafe main.cpp config/CafeConfig.h config/CafeConfig.cpp
        model/IDrink.h
        model/Tea.h
        model/Coffee.h
        model/Coffee.cpp
        model/Tea.cpp
        helper/DrinkFactory.h
        helper/DrinkFactory.cpp
        helper/CustomDrink.cpp
        helper/CustomDrink.h
        helper/IObserver.h
        helper/EmployeeObserver.cpp
        helper/EmployeeObserver.h
        helper/OrderSubject.cpp
        helper/OrderSubject.h
        helper/PaymentStrategy.h
        model/CreditCardPayment.cpp
        model/CreditCardPayment.h
        model/CashPayment.cpp
        model/CashPayment.h
        helper/Checkout.cpp
        helper/Checkout.h)
