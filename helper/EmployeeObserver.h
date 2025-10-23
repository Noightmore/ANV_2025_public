//
// Created on 10/23/25.
//

#ifndef HERG_CAFE_EMPLOYEEOBSERVER_H
#define HERG_CAFE_EMPLOYEEOBSERVER_H
#include "IObserver.h"


class EmployeeObserver final : public IObserver {

private:
    std::string name;
public:
    explicit EmployeeObserver(std::string employee_name) : name(std::move(employee_name)) {}

    void update(const std::string &status) override;

    ~EmployeeObserver() override = default;
};


#endif //HERG_CAFE_EMPLOYEEOBSERVER_H