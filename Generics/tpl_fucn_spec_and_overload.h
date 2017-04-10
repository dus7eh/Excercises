#pragma once

#include <iostream>

namespace util_tpl_specialization
{

    // Example 1: showing pitfalls in function specializing and overloading.
    // Depending on whether specialization is done for base template 1 or 3
    // calling f(int*) resolves to 3 (int* specialization ommitted) or 2 (specialization not ommitted)

    // function base template
    template<typename T>       // 1
    void func_spec(T val)
    {
        std::cout << "base\n";
    }

    // function full specialization
    template<>
    void func_spec<>(int* val)      // 2
    {
        std::cout << "ptr to int spec\n";
    }

    // function template overload (partial specialization not allowed)
    template<typename T>       // 3
    void func_spec(T* val)
    {
        std::cout << "base overload\n";
    }


    // Example 2: solution to the above problem
    // The function passes the call to a struct/class static method which allows full and partial specialization
    // Now all 3 implementations are considered as candidates equally
    template <typename T>
    struct FuncSpecImpl;

    template <typename T>
    void func_spec_wrapped(T val) { FuncSpecImpl<T>::func_spec_wrapped(val); }

    template <typename T>
    struct FuncSpecImpl
    {
        static void func_spec_wrapped(T val) { std::cout << "base\n"; }
    };

    template <typename T>
    struct FuncSpecImpl<T*>
    {
        static void func_spec_wrapped(T* val) { std::cout << "ptr spec\n"; }
    };

    template <>
    struct FuncSpecImpl<int*>
    {
        static void func_spec_wrapped(int* val) { std::cout << "ptr to int spec\n"; }
    };
}