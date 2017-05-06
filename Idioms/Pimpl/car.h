/**
    @author Damian Ellwart
    @version 0.1 2017
    Purpose:
*/

#pragma once

#include <memory>
#include "car_types.h"

class Car
{
public:
    Car(Types::CarColor color);
    ~Car();

    Car(const Car& rhs);
    Car(Car&& rhs);

    void runEngine();
    void openTrunk();

private:
    class CarImpl;
    std::unique_ptr<CarImpl> pimpl;
};