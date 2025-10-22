//
// Created on 10/22/25.
//

#ifndef HERG_CAFE_CUSTOMDRINK_H
#define HERG_CAFE_CUSTOMDRINK_H
#include <string>
#include <utility>


class CustomDrink {

private:
    std::string base;
    bool milk = false;
    bool sugar = false;
    bool caramel = false;

    explicit CustomDrink(std::string base, bool milk, bool sugar, bool caramel)
        : base(std::move(base)), milk(milk), sugar(sugar), caramel(caramel) {}
        // pass by value and use std::move for efficiency instead of pass by reference

public:
    class Builder;

    std::string toString() const;

    // Getters (optional, but useful)
    // std::string getBase() const { return base; }
    // bool hasMilk() const { return milk; }
    // bool hasSugar() const { return sugar; }
    // bool hasCaramel() const { return caramel; }
};


class CustomDrink::Builder {

private:
    std::string base;
    bool milk = false;
    bool sugar = false;
    bool caramel = false;

public:
    explicit Builder(std::string base) {
        this->base = base;
    }

    explicit Builder(const std::string& base) : base(base) {}

    Builder& withMilk() {
        this->milk = true;
        return *this;
    }

    Builder& withSugar() {
        this->sugar = true;
        return *this;
    }

    Builder& withCaramel() {
        this->caramel = true;
        return *this;
    }

    // Build method - creates the CustomDrink object
    CustomDrink build() const {
        return CustomDrink(base, milk, sugar, caramel);
    }
};
#endif //HERG_CAFE_CUSTOMDRINK_H

/*
Builder
Rozšiřte aplikaci kavárny pomocí návrhového vzoru Builder, aby si zákazník mohl přidat ke
svému nápoji některý z přídavků (např. mléko, cukr, apod.).
Vytvořte třídu CustomDrink. Třída by měla obsahovat privátní textový řetězec zastupující
základní nápoj (pojmenujte jej např. base). Dále by třída měla obsahovat příznaky
(boolean) pro jednotlivé dodatečné ingredience.
Uvnitř třídy CustomDrink vytvořte vnořenou třídu Builder, který bude opět obsahovat
base a příznaky ingrediencí. Konstruktor Builder(String base) uloží do base název
nápoje. Pro každou ingredienci bude vytvořena vlastní metoda (např. milk()), která nastaví
příslušné příznaky na true a vrátí this (např. this.milk = true; return this;).
Třída CustomDrink bude mít privátní konstruktor CustomDrink(Builder b), který
převezme hodnoty base a příznaky z builderu b a hodnoty uloží do příznaků třídy.
Dále vytvořte Metodu build() ve třídě Builder, která vrátí novou instanci CustomDrink:
public CustomDrink build() {return new CustomDrink(this);}
Teď už je možné přepsat toString() v CustomDrink tak, aby vracela text servírování
z třídy DrinkFactory společně se zvolenými přídavky např. následovně:
return DrinkFactory.createDrink(base).serve()
+ (milk ? ", milk" : "")
+ (sugar ? ", sugar" : "")
+ (caramel ? ", caramel" : "");
V hlavní třídě si následně vyzkoušejte funkčnost nového rozšíření:
CustomDrink customDrink =
new CustomDrink.Builder("coffee").milk().sugar().build();
System.out.println(customDrink
+" in "+CafeConfig.getInstance().getCafeName());
Pozn.: Hotová aplikace je taková, která není otestována pouze Vámi, ale především unit testy.
 */