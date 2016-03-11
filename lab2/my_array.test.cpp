#include <iostream>

#include "my_array.h"
#include "my_string.h"
#include "../time_measure.hpp"
#include <stdlib.h>
#include <vector>


int main ()
{
    MyArray<int> ma1 = {1,2,3,4,5,6,7};
    MyArray<int> ma2 = {2};

    ///Copy constructor
    ma2 = ma1;

    std::cout << ma1 << ma2 << std::endl;

    ///Move constructor
    MyArray<float> maf1 = {5.};

    maf1.push(5.4);
    maf1.push(33.2);
    std::cout << maf1.pop();

    std::cout << "maf1 = " << maf1 << std::endl;

    {
        raii_time ri;

        for (size_t i = 0; i < 100000000; i++)
            maf1.push(rand() % 1000);
        //std::cout << "maf1 after 1000pushes: " << maf1 << std::endl;
        std::cout << "maf1 calls realloc:" << maf1.reallocs_calls;

    }

    std::cout << "time spent: " << last_result << "ms" << std::endl;

    std::vector<float> vaf1 = {5. , 4., 121.2,};
    {
        raii_time ri;

        for (size_t i = 0; i < 100000000; i++)
            vaf1.push_back(rand() % 1000);
        //std::cout << "maf1 after 1000pushes: " << maf1 << std::endl;
    }

    std::cout << "VVV time spent: " << last_result << "ms" << std::endl;


    MyArray<MyString>  ar1 { MyString("AAA"), MyString ("qwerty"), MyString("blabla")};

    std::cout << ar1;


    return 0;
}
