/**
    @author Damian Ellwart
    @version 0.1 2016
    Purpose:
*/

#include "return_type_deduction.h"

int main()
{
    // return type deduction
    decltype(auto) intVal = rtd::returnIntVal(); // returns value - OK
    decltype(auto) intRef1 = rtd::returnIntRef1(); // actually returns val - missing decltype() in function return type
    decltype(auto) intRef2 = rtd::returnIntRef2(); // returns ref - OK
    decltype(auto) intRef3 = rtd::returnIntRef3(); // actually returns val - missing () around returned var
}