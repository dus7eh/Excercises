/**
    @author Damian Ellwart
    @version 0.1 2016
    Purpose: 
*/

#include "enable_if_examples.h"

int main()
{
    using util_tpl::concat;
    using util_tpl::add;
    using util_tpl::subtract;
    using util_tpl::multiply;

    auto valInt = 9;
    auto valFloat = .6f;

    auto conI1 = concat(1, 6);
    //auto conF1 = concat(.5f, .6f);

    auto addI1 = add(6, 5);
    //auto addF1 = add(0.6f, 0.3f);

    auto subI1 = subtract(6, 3);
    //auto subF1 = subtract(0.4f, .9f);

    auto mulI1 = multiply(6, 2);
    //auto mulF1 = multiply(0.5f, .2f);

    using util_tpl::Printer;
    Printer<int> printerInt;
    printerInt.show(567);

    Printer<float> printerFloat1;
    printerFloat1.show(.55f);

    Printer<const float> printerFloat2;
    printerFloat2.show(.89f);

    Printer<float, void> pr;
    pr.show(2);

    using util_tpl::Adder;
    Adder<int> adder1;
    auto adder1Val = adder1.add(5, 4);

    Adder<float> adder2;
    auto adder2Val = adder2.add(8, 6);

    Adder<double> adder3;
    auto adder3Val = adder3.add(8, 9);

    return 0;
}