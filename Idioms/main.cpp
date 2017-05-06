/**
    @author Damian Ellwart
    @version 0.1 2017
    Purpose:
*/

#include "Pimpl\car.h"

namespace
{
    void check_pimpl_idiom()
    {
        Car car{ Types::CarColor::Silver };
        car.runEngine();
        car.openTrunk();

        auto copied_car = car;
        auto moved_car = std::move(car);
    }
}

#include <vector>
#include <fstream>
#include <iostream>
#include <iterator>

class Writer
{
public:
    Writer(std::string name) : file{ name, std::ios_base::out | std::ios_base::trunc} {}

    template <typename T>
    Writer& operator<<(T&& data)
    {
        file << data;
        return *this;
    }

private:
    std::fstream file;
};

class SerializeMe
{
public:
    SerializeMe() : data{ 0, 1 , 5, 6 } {}
    std::ostream& write(std::ostream& s) const
    {
        s << data.size() << ':';
        std::copy(std::begin(data), std::end(data), std::ostream_iterator<decltype(data)::value_type>(s, ""));
        return s;
    }

private:
    std::vector<uint8_t> data;
};

std::ostream& operator<<(std::ostream& s, const SerializeMe& obj)
{
    return obj.write(s);
}

int main()
{
    check_pimpl_idiom();

    Writer writer("sample.txt");
    SerializeMe object;
    writer << object << object;
    
    const int value = 2;
    double v2 = .6;

    int& value_cast = (int&)value;
    value_cast = 8;
    int& value_d = (int&)v2;
    value_d = 8.1;

    return 0;
}