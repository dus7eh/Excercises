/**
    @author Damian Ellwart
    @version 0.1 2016
    Purpose: 
*/

#include "enable_if_examples.h"
#include "template_specialization.h"
#include "tpl_fucn_spec_and_overload.h"
#include "tpl_func_spec_value.h"

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

void run_template_func_value_spacialization()
{
    using namespace util_tpl_specialization;
    process<RunType::One>();
    process<RunType::Two>();
    process<RunType::Three>();

    auto type = RunType::Two;
    //process<type>();          // this is not a compile time constant: Error!

    constexpr auto ct_type = RunType::Two;
    process<ct_type>();          // this is a compile time constant: OK!
}



int main()
{
    util_tpl::run_enable_if();
    run_template_specialization();
    run_template_func_specialization();
    run_template_func_value_spacialization();

    return 0;
}