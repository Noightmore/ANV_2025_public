//
// Created on 12/9/25.
//

#ifndef HERG_CAFE_PREPARABLEDRINK_H
#define HERG_CAFE_PREPARABLEDRINK_H

namespace model {
    class PreparableDrink {
    public:
        virtual ~PreparableDrink() = default;
        virtual void prepare() = 0;
    };
} // model

#endif //HERG_CAFE_PREPARABLEDRINK_H