#pragma once
#include <iostream>
#include <vector>

namespace util_tpl_specialization
{
    // function templates

    // return type template
    template<typename T>
    T calculateDistance(int x1, int x2)
    {
        return static_cast<T>(x1 - x2);
    }

    template <typename T, int C>
    void printOutContents(T data)
    {
        std::cout << data << std::endl;
    }

    template <typename T, int C>
    void printOutContents(const std::vector<T>& data)
    {
        std::cout << "T: ";
        for (const auto& item : data)
            std::cout << item << " ";
        std::cout << std::endl;
    }

    template <typename T = char, int C>
    void printOutContents(const std::vector<char>& data)
    {
        std::cout << "char: ";
        for (const auto& item : data)
            std::cout << static_cast<short>(item) << " ";
        std::cout << std::endl;
    }

    // class templates
}