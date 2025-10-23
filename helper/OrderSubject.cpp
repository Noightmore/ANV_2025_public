//
// Created on 10/23/25.
//

#include "OrderSubject.h"

void OrderSubject::addObserver(IObserver *observer) {
    observers.push_back(observer);
}

void OrderSubject::notifyAll(const std::string &status) const {
    for (auto& observer : observers) {
        observer->update(status);
    }
}
