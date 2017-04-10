/**
    @author Damian Ellwart
    @version 0.1 2016
    Purpose: 
*/

#include "enable_if_examples.h"
#include "template_specialization.h"
#include "tpl_fucn_spec_and_overload.h"

void run_template_specialization()
{
    using util_tpl_specialization::calculateDistance;
    using util_tpl_specialization::printOutContents;

    auto dist1 = calculateDistance<long>(4, 5);
    auto dist2 = calculateDistance<long long>(5, 6);
    auto dist3 = calculateDistance<char>(3, 5);

    printOutContents<int, 1>(5);

    std::vector<int> dataInt{ 4, 3, 2 };
    printOutContents<int, 3>(dataInt);

    std::vector<char> dataChar{ 7, 8, 9 };
    printOutContents<char, 3>(dataChar);
}

void run_template_func_specialization()
{
    int value = 6;
    util_tpl_specialization::func_spec(value);
    util_tpl_specialization::func_spec(&value);

    util_tpl_specialization::func_spec_wrapped(value);
    util_tpl_specialization::func_spec_wrapped(&value);
}

struct TestStruct
{
    TestStruct() : field_a(5), field_b(6) {}

    int field_a;
    char field_b;
};



#include <algorithm>
#include <array>
int main()
{
    util_tpl::run_enable_if();
    run_template_specialization();
    run_template_func_specialization();

    TestStruct t0;
    TestStruct t1{};
    TestStruct t2 = TestStruct();
    TestStruct *t3 = new TestStruct;
    TestStruct *t4 = new TestStruct();

    return 0;
}