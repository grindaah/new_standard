#include <iostream>
#include <vector>
#include "iterator_add.hpp"

int main()
{
    int ar1[5] = { 22, 23, 24, 25, 26 };

    for (auto it = my_begin(ar1); it != my_end(ar1); ++it)
        std::cout << *it << " ";

    std::cout << "If you see this - array test passed" << std::endl;
    std::cout << "OK" << std::endl;

    std::vector< int > v1 = {5, 6, 7, 8, 9, 10, 11, 12 };

    for (auto it = my_begin(v1); it != my_end(v1); ++it)
        std::cout << *it << " " << std::endl;

    std::cout << "If you see this - vector test passed" << std::endl;
    std::cout << "OK";

}
