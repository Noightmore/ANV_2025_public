//
// Created on 12/9/25.
//

#ifndef HERG_CAFE_CUSTOMDRINKDECORATOR_H
#define HERG_CAFE_CUSTOMDRINKDECORATOR_H
#include "CustomDrink.h"

namespace helper {
    class CustomDrinkDecorator : public CustomDrink {

    public:
        explicit CustomDrinkDecorator(CustomDrink& drink)
        : CustomDrink(drink),
         wrapped_(drink) {}

        std::string toString() const override {
            return wrapped_.toString();            // default: just delegate
        }
    protected:
        CustomDrink& wrapped_;
    };
} // helper

#endif //HERG_CAFE_CUSTOMDRINKDECORATOR_H

/*
Decorator (Dekorátor)
Rozšiřte aplikaci „Smart Café“ o možnost vzít si nápoj s sebou nebo do vlastního hrnku
s využitím vzoru Decorator. Při výpisu objednávky tak bude možné přidat k produktu
[to-go] nebo [own mug] (případně obojí).
Nápověda
Pokud je potřeba, proveďte úpravy třídy CustomDrink, aby ze třídy šlo dědit, a vytvořte
abstraktní třídu CustomDrinkDecorator, která ze třídy dědí. Třída bude mít konstruktor,
v rámci něhož bude třídě předána instance třídy CustomDrink, a bude přepisovat metodu
toString(), která bude vracet customDrink.toString().
Dále implementujte třídu ToGoDecorator a OwnMugDecorator, obě dědí ze třídy
CustomDrinkDecorator. Třídy budou v rámci přepisu metody toString() přidávat
k základnímu výpisu navíc [to-go] nebo [own mug].
*/