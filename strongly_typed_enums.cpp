#include <iostream>

enum
{
    Red, Green, Blue
};


///note: enum class, not just enum
enum class States
{
   Ok, Fail, Warning
      // , Red  === will be redefinition
};

int main()
{
    int state = 0;

    //without static_cast will not be compiled
    if (static_cast<States> (state) == States::Ok)
        std::cout << "OK" << std::endl;
    else
        std::cout << "Not ok";
    return 0;
}


