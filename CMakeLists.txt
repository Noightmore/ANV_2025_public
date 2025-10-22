cmake_minimum_required(VERSION 3.25)
project(hergesel_cafe)

set(CMAKE_CXX_STANDARD 23)

add_executable(hergesel_cafe main.cpp config/CafeConfig.h config/CafeConfig.cpp
        model/IDrink.h
        model/Tea.h
        model/Coffee.h
        model/Coffee.cpp
        model/Tea.cpp
        model/DrinkFactory.h
        model/DrinkFactory.cpp
        model/CustomDrink.cpp
        model/CustomDrink.h)
