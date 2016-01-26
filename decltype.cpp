#include <iostream>


int main()
{
    int x=1;
    decltype(x) y;

    //y = 2;

    std::cout << "y=" << y << std::endl;

    //prefix++ will return lvalue, but expression will not be performed
    //it will be used only for type deduction
    decltype(++x) z = y;

    std::cout << "x=" << x << ",z=" << z <<std::endl;

    return 0;
}
