/**
    @author Damian Ellwart
    @version 0.1 2017
    Purpose:
*/

#include "car.h"
#include "car_impl.h"

Car::Car(Types::CarColor color) : pimpl{std::make_unique<Car::CarImpl>(color)}
{
}

Car::~Car() = default;

Car::Car(const Car& rhs) : pimpl{ std::make_unique<Car::CarImpl>(*rhs.pimpl)}
{
}

Car::Car(Car&& rhs) : pimpl{ std::move(rhs.pimpl) }
{
}

void Car::runEngine()
{
    pimpl->runEngine();
}

void Car::openTrunk()
{
    pimpl->openTrunk();
}