/**
    @author Damian Ellwart
    @version 0.1 2017
    Purpose:
*/

#include <assert.h>
#include <utility>
#include <string>

namespace
{
    namespace
    {
        int get_int() { return 11; }
    }

    void run_auto_deduction()
    {
        // simple case with lvalue
        int v2 = 9;
        int& v2_ref = v2;
        auto v2_auto = v2; // int - simple copy
        auto v2_ref_auto = v2_ref; // int - simple copy
        auto& v2_auto_ref = v2; // int&
        const auto& v2_auto_const_ref = v2; // const int&
        auto&& v2_auto_univ = v2; // int&

        // with cv qualifiers
        const int v1 = 5;
        const int& v1_ref = v1;
        auto v1_auto = v1;  // int - simple copy
        auto v1_ref_auto = v1_ref; // int - simple copy
        auto& v1_auto_ref = v1; // const int&
        const auto& v1_auto_const_ref = v1; // const int&
        auto&& v1_auto_univ = v1; // const int &

        // rvalue samples
        auto func_auto = get_int(); // int
        const auto& func_auto_const_ref = get_int(); // const int&
        auto&& func_auto = get_int(); // int&&

        // initializer list, literals and similar
        auto auto_int{ 1 };   // int!
        //auto init_list1{ 0, 1, 2, 3 }; // error!
        auto init_list2 = { 0, 1, 2, 3 }; // initializer list
        auto value_const_char_ptr = "abc"; // const char*
        auto value_long = 123L;
        auto value_long_long = 123LL;
        auto value_unsigned = 123u;
        auto value_float = .123f;
    }
}

int main()
{
    

    return 0;
}