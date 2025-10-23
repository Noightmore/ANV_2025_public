//
// Created on 10/23/25.
//

#ifndef HERG_CAFE_IOBSERVER_H
#define HERG_CAFE_IOBSERVER_H
#include <string>


class IObserver {

public:
    virtual void update(const std::string& status) = 0;

    virtual ~IObserver() = default;
};


#endif //HERG_CAFE_IOBSERVER_H

/*
Observer (Pozorovatel)
Rozšiřte aplikaci „Smart Café“ o notifikace objednávek pro personál na základě návrhového
vzoru Observer.
Vytvořte rozhraní Observer, které bude předepisovat metodu update se vstupním
parametrem status typu String. Následně vytvořte třídu EmployeeObserver, která toto
rozhraní implementuje. Konstruktoru bude předáno jméno (může být případně pracovní
pozice) zaměstnance.
Metoda update v rámci třídy bude vypadat následovně:
System.out.println(name + " notified: " + status);
Nakonec vytvořte třídu OrderSubject. Třída bude obsahovat ArrayList, do kterého bude
možné přidávat nové instance třídy Observer. Za tímto účelem vytvořte metodu
addObserver, pomocí které bude možné observery přidávat. Dále vytvořte metodu
notifyAll se vstupem typu String, která projde ArrayList a pro všechny zaměstnance
postupně zavolá metodu update.
Nakonec se vraťte k jednotlivým nápojům a upravte jejich výpis tak, aby místo o servírování
informovaly o objednávce (např. „Ordered Coffee“). Je na vás, zda to budete měnit „natvrdo“,
nebo v rámci úpravy předchozí funkcionalitu vylepšíte, aby nebylo nutné při další změně
měnit slova v každé metodě zvlášť.
Tělo hlavní třídy může vypadat následovně:
OrderSubject order = new OrderSubject();
order.addObserver(new EmployeeObserver("Barista"));
order.addObserver(new EmployeeObserver("Waiter"));
CustomDrink customDrink = new CustomDrink.Builder("coffee").milk().sugar().build();
String msg = customDrink +" in "+CafeConfig.getInstance().getCafeName();
order.notifyAll(msg);
Všichni observeři by měli dostat notifikaci, že byla přijata objednávka:
Barista notified: Ordered Coffee, milk, sugar in Smart Café
Waiter notified: Ordered Coffee, milk, sugar in Smart Café
 */