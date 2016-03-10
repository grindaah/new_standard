#include <iostream>

#include "my_array.h"
#include "my_string.h"
#include <stdlib.h>


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

    for (size_t i = 0; i < 1000; i++)
        maf1.push(rand() % 1000);
    std::cout << "maf1 after 1000pushes: " << maf1 << std::endl;
    std::cout << "maf1 calls realloc:" << maf1.reallocs_calls;

    MyArray<MyString>  ar1 { MyString("AAA"), MyString ("qwerty"), MyString("blabla")};

    std::cout << ar1;


    return 0;
}
