#include "wrap_any.h"

#include "my_string.h"


int main()
{
    //WrapAny wrap1 = WrapAny (MyString("blabla"));
    WrapAny wrap1 = WrapAny(std::string("blabla"));
    WrapAny wrap2 = WrapAny (int(5));
    WrapAny wrap3 = WrapAny (float(3));


    std::cout << "wrap1=" << wrap1 << std::endl;
    std::cout << "wrap2=" << wrap2 << std::endl;
    std::cout << "wrap3=" << wrap3 << std::endl;
    WrapAny w = wrap2 + wrap3;
    std::cout << "wrap2+wrap3=" << w << std::endl;

    w += wrap2;
    std::cout << "w+=wrap2=" << w << std::endl;
    ///mustbe 535

    w += wrap2 + wrap1;
    ///must be 5355blabla
    std::cout << "+= result " << w << std::endl;


}
