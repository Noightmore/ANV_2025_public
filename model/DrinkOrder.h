//
// Created on 12/9/25.
//

#ifndef HERG_CAFE_DRINKORDER_H
#define HERG_CAFE_DRINKORDER_H
#include <iostream>
#include <memory>
#include <vector>

#include "PreparableDrink.h"

namespace model {
    class DrinkOrder : public PreparableDrink {
    public:
        void add(std::unique_ptr<PreparableDrink> drink) {
            drinks_.push_back(std::move(drink));
        }

        // optional: remove by index or pointer; simplest version: no-op or not used
        void remove(size_t index) {
            if (index < drinks_.size()) {
                drinks_.erase(drinks_.begin() + static_cast<long>(index));
            }
        }

        std::size_t getCount() const {
            return drinks_.size();
        }

        void prepare() override {
            std::cout << "[APP] Mobile order contains "
                      << getCount() << " drink(s)\n";

            for (auto& drink : drinks_) {
                if (drink) {
                    drink->prepare();      // 👈 template preparation called here
                }
            }

            std::cout << "[APP] Mobile order prepared\n";
        }

    private:
        std::vector<std::unique_ptr<PreparableDrink>> drinks_;
    };
} // model

#endif //HERG_CAFE_DRINKORDER_H