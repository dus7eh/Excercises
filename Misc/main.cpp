/**
    @author Damian Ellwart
    @version 0.1 2016
    Purpose:
*/

#include "return_type_deduction.h"
#include "trival_pod_aggregates.h"
#include <memory>
#include <algorithm>

namespace
{
    void check_return_type_deduction()
    {
        decltype(auto) intVal = rtd::returnIntVal(); // returns value - OK
        decltype(auto) intRef1 = rtd::returnIntRef1(); // actually returns val - missing decltype() in function return type
        decltype(auto) intRef2 = rtd::returnIntRef2(); // returns ref - OK
        decltype(auto) intRef3 = rtd::returnIntRef3(); // actually returns val - missing () around returned var
    }

    void check_destr_inheritance()
    {
        std::unique_ptr<Base> b2b(new Base());
        std::unique_ptr<Base> b2f(new FirstDescendant());
        std::unique_ptr<Base> b2d(new SecondDescendant());

    }

    void check_data_initialization()
    {
        using trivs::TestStruct;

        TestStruct t0;
        TestStruct t1{};
        TestStruct t2 = TestStruct();
        TestStruct *t3 = new TestStruct;
        TestStruct *t4 = new TestStruct();

        TestStruct *t = new TestStruct();
        auto tt = t;
    }

    void check_aliasing()
    {
        constexpr int tableSize = 10;
        int table[tableSize];
        int n{ 0 };
        std::generate(std::begin(table), std::end(table), [&n] { return n++; });

        int* refValue = &table[5];
        for (int i = 0; i < tableSize; ++i)
        {
            table[i] += *refValue;
        }

        std::for_each(std::begin(table), std::end(table), [](const auto &item) { std::cout << item << ", "; });
    }
}

int main()
{
    check_return_type_deduction();
    check_destr_inheritance();
    check_data_initialization();
    check_aliasing();
}