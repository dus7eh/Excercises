/**
    @author Damian Ellwart
    @version 0.1 2017
    Purpose:
*/

#pragma once
#include <iostream>
#include "car_types.h"

class Car::CarImpl
{
public:
    CarImpl(Types::CarColor color) : color{ color } {}

    void runEngine() { std::cout << "brrruuuuummm\n"; }
    void openTrunk() { std::cout << "click! trunk opened\n"; }

private:
    Types::CarColor color;
};