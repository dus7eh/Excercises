/**
    @author Damian Ellwart
    @version 0.1 2016
    Purpose: 
*/

#pragma once
#include <string>
#include <iostream>

namespace util_tpl
{
    void run_enable_if();

    // enable via argument
    template<typename T>
    std::string concat(T t1, T t2, typename std::enable_if<std::is_same<T, int>::value>::type * = nullptr)
    {
        return std::to_string(t1) + std::to_string(t2);
    }

    // enable via return type - should allow parameter type deduction
    template<typename T>
    typename std::enable_if<std::is_integral<T>::value, T>::type
    add(T t1, T t2)
    {
        return t1 + t2;
    }

    // enable via template argument
    template <typename T, typename std::enable_if<std::is_integral<T>::value, T>::type = 0>
    T subtract(T t1, T t2)
    {
        return t1 - t2;
    }

    // enable via tempalte argument using helper
    template <typename T, typename std::enable_if_t<std::is_integral<T>::value, T> = 0>
    T multiply(T t1, T t2)
    {
        return t1 * t2;
    }

    // class specialization with enable_if
    template <typename T, typename E = void>
    class Printer
    {
    public:
        void show(T t) { std::cout << "integral: " << std::to_string(t) << " " << typeid(t).name() << " " << typeid(E).name() << std::endl; }
    };

    template <typename T>
    class Printer<T, typename std::enable_if<std::is_floating_point<T>::value>::type>
    {
    public:
        void show(T t)
        {
            typedef std::enable_if<std::is_floating_point<T>::value>::type e;
            std::cout << "floating: " << std::to_string(t) << " " << typeid(t).name() << " " << typeid(e).name() << std::is_floating_point<float>::value << std::endl;
        }
    };

    // verify template type matching
    template <typename T = int>
    class Adder
    {
    public:
        long add(T t1, T t2) { return (int)t1 + (int)t2; }
    };

    template <>
    class Adder<float>
    {
    public:
        double add(float t1, float t2) { return t1 + t2; }
    };
}

#include <vector>
namespace detail
{
    template<typename T>
    struct is_vector { static const bool value = false; };

    template<typename T, typename A>
    struct is_vector<std::vector<T, A>> { static const bool value = true; };

    template<typename T, typename = std::enable_if<is_vector<T>::value>::type>
    void func(T value)
    {
        ;
    }

    template<typename T>
    typename std::enable_if_t<is_vector<T>::value, T>
        func2(T&& v1, T&& v2)
    {
        T result = v1;
        result.reserve(v1.size() + v2.size());
        result.insert(result.end(), v2.begin(), v2.end());
        return result;
    }
}