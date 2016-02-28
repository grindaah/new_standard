#include "wrap_any.h"

#include "my_string.h"


int main()
{
    WrapAny wrap1 = WrapAny (MyString("blabla"));
    WrapAny wrap2 = WrapAny (int(5));
    WrapAny wrap3 = WrapAny (float(3));


    std::cout << "wrap1=" << wrap1 << std::endl;
    std::cout << "wrap2=" << wrap2 << std::endl;
    WrapAny w = wrap2 + wrap3;
    std::cout << "wrap2+wrap3=" << w << std::endl;

}
