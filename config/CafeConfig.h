//
// Created on 10/22/25.
//

#ifndef HERG_CAFE_CAFECONFIG_H
#define HERG_CAFE_CAFECONFIG_H


#include <string>
#include <string_view>

class CafeConfig {

private:

    // is an equivalent to this: CafeConfig() {}
    // meaning just give me a simple default constructor
    CafeConfig() = default;

    constexpr static std::string cafeName = "Smart Café";

public:
    // Delete copy constructor and assignment operator to enforce singleton
    // making this  illegal!
    // CafeConfig& config1 = CafeConfig::getInstance();
    // CafeConfig& config2 = CafeConfig::getInstance();
    // config1 = config2; // ERROR: copy assignment is deleted

    // Prevents creating COPIES:
    // CafeConfig copy = original;  // ERROR
    CafeConfig(const CafeConfig&) = delete; //

    // Prevents ASSIGNMENT between instances:
    // original1 = original2;  // ERROR
    CafeConfig& operator=(const CafeConfig&) = delete;

    // Get the singleton instance
    static CafeConfig& getInstance();

    // Using string_view for efficient read-only access
    std::string_view getCafeName();

    // Alternative if you need to modify the name
    //void setCafeName(std::string_view newName);
};

#endif //HERG_CAFE_CAFECONFIG_H

/*
Singlenon (Jedináček)
Naprogramujte malou konzolovou aplikaci „Smart Café“. Aplikace bude (mimo hlavní třídu)
obsahovat třídu CafeConfig, která bude realizována jako Singleton, a tedy bude zajištěno,
        aby od dané třídy existovala vždy maximálně jedna instance.
Třída CafeConfig bude obsahovat dvě metody. První metodou bude getInstance(), která
vrátí instanci třídy, která je ve třídě uložena. Pokud instance neexistuje, metoda ji vytvoří. Za
        tímto účelem musí existovat privátní konstruktor, jinak nebude zajištěno, že v programu
        nemůže existovat více instancí této třídy!!!
Druhou metodou bude getCafeName(). Tato metoda bude vracet jméno kavárny (v rámci
        třídy může být uloženou např. jako konstanta). Pokud budete chtít tuto metodu volat zvenčí,
mělo by to být možné pouze následovně:
System.out.printf(CafeConfig.getInstance().getCafeName());
Pozn.: Hotová aplikace je taková, která není otestována pouze Vámi, ale především unit testy.
*/