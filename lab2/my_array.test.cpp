#include <iostream>

#include "my_array.h"


int main ()
{
    MyArray<int> ma1 = {1,2,3,4,5,6,7};
    MyArray<int> ma2 = {};

    ///Copy constructor
    ma2 = ma1;

//    std::cout << ma1 << ma2;

    ///Move constructor
    MyArray<float> maf1 = {5.};

    maf1.push(5.4);
    maf1.push(33.2);

    std::cout << "maf1 = " << maf1 << std::endl;



    return 0;
}
