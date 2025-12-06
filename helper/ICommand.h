//
// Created on 11/20/25.
//

#ifndef HERG_CAFE_ICOMMAND_H
#define HERG_CAFE_ICOMMAND_H

namespace command {
    class ICommand {

    public:
        virtual void execute() = 0;

        virtual ~ICommand() = default;
    };
}
#endif //HERG_CAFE_ICOMMAND_H

/*
Command
Upravte aplikaci „Smart Café“, aby objednávky a platby probíhaly pomocí návrhové vzoru
Command. Každá notifikace by tedy nově měla proběhnout v příslušné třídě (pro objednávku
nebo platbu).
Nápověda
Vytvořte rozhraní Command, které bude předepisovat metodu execute(). Následně vytvořte
třídy OrderCommand a PaymentCommand, které rozhraní implementují. V rámci
konstruktoru každá je oběma třídám předán příslušný OrderSubject (aby bylo možné
notifikovat všechny zaregistrované subjekty) a informace potřebné pro objednávku nebo
platbu. V rámci metody execute() pak proběhne notifikace všech zaregistrovaných
subjektů.
 */