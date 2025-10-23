//
// Created on 10/23/25.
//

#include "EmployeeObserver.h"

#include <iostream>
#include <ostream>

void EmployeeObserver::update(const std::string &status) {
    std::cout << name << " notified: " << status << std::endl;
}
