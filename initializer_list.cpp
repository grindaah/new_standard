#include <iostream>

#include "templ_summ2.hpp"

int main()
{

    std::initializer_list<int> iList1 = { 1, 2, 3, 4, 5 };

    std::initializer_list<int> iList2 = { 7, 8, 9};

    iList1 = iList2;

    print_all (iList1);
    print_all (iList2);
    std::cout << "iList1 addr = " << &iList2 << std::endl;
    std::cout << "iList2 addr = " << &iList1 << std::endl;

    return 0;
}

