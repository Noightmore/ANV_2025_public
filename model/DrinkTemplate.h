//
// Created on 12/9/25.
//

#ifndef HERG_CAFE_DRINKTEMPLATE_H
#define HERG_CAFE_DRINKTEMPLATE_H
#include <iostream>

#include "PreparableDrink.h"

namespace model {
    class DrinkTemplate : public PreparableDrink {
    public:
        explicit DrinkTemplate(std::string name)
            : name_(std::move(name)) {}

        void prepare() override {
            std::cout << "[APP] Starting preparation: " << name_ << '\n';
            boilWater();
            brew();     // 👈 implemented in subclasses
            pour();
            std::cout << "[APP] Done: " << name_ << '\n';
        }

    protected:
        virtual void brew() = 0;  // pure virtual, each drink does this differently

        virtual void boilWater() {
            std::cout << "[APP] Boiling water for " << name_ << '\n';
        }

        virtual void pour() {
            std::cout << "[APP] Pouring " << name_ << " into cup\n";
        }

        std::string name_;
    };
} // model

#endif //HERG_CAFE_DRINKTEMPLATE_H

/*
Template a Composite
Rozšiřte aplikaci „Smart Café“ o podporu objednávek z mobilní aplikace, ve které zákazník
může sledovat jednotlivé kroky přípravy svých nápojů.
Příprava každého nápoje se skládá z několika kroků: uvaření vody, příprava samotného nápoje
(každý druh nápoje by se měl připravovat jinak) a nalití do šálku. Pro popsanou funkcionalitu
využijte vzor Template. Samotná objednávka se pak může skládat z více položek. Zde
postupujte dle návrhového vzoru Composite.
Pro zjednodušení nemusí nové třídy umět pracovat s přídavky (cukr apod.) ani s dalšími
možnostmi pro nápoj (vlastní hrnek, „to-go“).
Nápověda
Vytvořte nové rozhraní PreparableDrink, které bude předepisovat metodu prepare().
Dále vytvořte abstraktní třídu DrinkTemplate, která toto rozhraní implementuje. V rámci
konstruktoru bude třídě předáno jméno nápoje.
Metoda prepare() zde může vypadat náledovně:
System.out.println("[APP] Starting preparation: " + name);
boilWater();
brew();
pour();
System.out.println("[APP] Done: " + name);
Metody boilWater() a pour() implementujte v této třídě (opět stačí jednoduchý výpis do
konzole). Následně upravte třídy nápojů (např. Tea, Coffee), aby nově navíc dědily ze třídy
DrinkTemplate. Každá třída nápoje by navíc měla implementovat vlastní verzi metody
brew(). Pokud navíc nechcete zahrnovat do objednávek různá obohacení nápoje, vytvořte
pro třídy také konstruktory.
Nakonec vytvořte třídu DrinkOrder, která bude také implementovat PreparableDrink.
Třída by měla obsahovat seznam obsahující objekty typu PreparableDrink, dále metody
add(PreparableDrink drink), remove(PreparableDrink drink) a getCount()
pro práci s objednávkou. Nakonec v rámci metody přepište metodu prepare(), která
nejprve do konzole informuje o celkovém počtu nápojů v objednávce, následně pro každou
položku v objednávce zavolá metodu prepare() a nakonec vypíše, že je objednávka
připravená.
*/