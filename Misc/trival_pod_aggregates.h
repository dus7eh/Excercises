/**
    @author Damian Ellwart
    @version 0.1 2017
    Purpose:
*/

#pragma once

#include <iostream>

namespace trivs
{
    struct TestStruct
    {
        int field_a;
        char field_b;
    };
}

class Base
{
public:
    virtual ~Base() { std::cout << "Base\n"; }
};

class FirstDescendant : public Base
{
};

class SecondDescendant : public FirstDescendant
{
public:
    ~SecondDescendant() { std::cout << "Second descendant\n"; }
};