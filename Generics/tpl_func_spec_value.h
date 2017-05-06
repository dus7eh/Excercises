#pragma once

#include <iostream>


namespace util_tpl_specialization
{
    enum class RunType
    {
        One,
        Two,
        Three,
    };

    template <RunType type>
    void process()
    {
        std::cout << "process general\n";
    }

    template <>
    void process<RunType::Two>()
    {
        std::cout << "process two\n";
    }
}