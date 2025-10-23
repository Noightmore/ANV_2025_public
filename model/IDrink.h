//
// Created on 10/22/25.
//

#ifndef HERG_CAFE_DRINK_H
#define HERG_CAFE_DRINK_H
#include <string>


class IDrink {

private:

protected:
    constexpr static std::string default_serve_message = "Serving Drink";

public:
    virtual std::string_view serve() const = 0; // Pure virtual function to be implemented by derived classes

    virtual ~IDrink() = default; // Virtual destructor for proper cleanup of derived classes
};

#endif //HERG_CAFE_DRINK_H

/*
Factory (Továrna)
Rozšiřte aplikaci kavárny o možnost servírování drinků.
Nejprve si vytvořte rozhraní Drink:
public interface Drink {
public String serve();
}
Dále vytvořte alespoň dvě další třídy, které reprezentují nápoje (čaj, káva, apod.) a rozhraní
Drink implementují. Metoda serve() by měla vracet text např. v podobě „Serving Tea“.
Nakonec vytvořte třídu DrinkFactory dle návrhového vzoru Factory. Třída bude obsahovat
metodu createDrink s jedním vstupním parametrem, který bude určovat typ nápoje, a její
návratová hodnota bude typu Drink. Metoda při zavolání vytvoří zvolený nápoj (vrátí
instanci příslušné třídy).
Díky třídě DrinkFactory pak můžete hlavní třídu rozšířit následovně:
System.out.println(DrinkFactory.createDrink("tea").serve() + " in" +
CafeConfig.getInstance().getCafeName());
Pozn.: Hotová aplikace je taková, která není otestována pouze Vámi, ale především unit test

 */