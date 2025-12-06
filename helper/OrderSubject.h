//
// Created on 10/23/25.
//

#ifndef HERGL_CAFE_ORDERSUBJECT_H
#define HERG_CAFE_ORDERSUBJECT_H

#pragma once

#include <vector>

#include "IObserver.h"


class OrderSubject {
private:
    std::vector<IObserver*> observers;

public:
    void addObserver(IObserver *observer);
    void notifyAll(const std::string &status) const;
};


#endif //HERG_CAFE_ORDERSUBJECT_H