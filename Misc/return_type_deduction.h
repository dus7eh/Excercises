/**
    @author Damian Ellwart
    @version 0.1 2016
    Purpose: 
*/

#pragma once

namespace rtd
{
    constexpr int gInt = 7;

    auto returnIntVal()
    {
        return 8;
    }

    auto returnIntRef1()
    {
        return (gInt);
    }

    decltype(auto) returnIntRef2()
    {
        return (gInt);
    }

    decltype(auto) returnIntRef3()
    {
        return gInt;
    }
}