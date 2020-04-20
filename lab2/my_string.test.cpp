#include "my_string.h"

int main()
{
    ///default constructor
    MyString mstr1();
    ///char* constructor
    MyString mstr2("mstr2");
    std::cout << "mstr2 = "  << mstr2 << std::endl;
    ///Copy constructor
    MyString mstr3(mstr2);
    std::cout << "mstr2 = "  << mstr2 << std::endl;
    std::cout << "mstr3 = "  << mstr3 << std::endl;
    ///Operator = (+Copy constructor
    MyString mstr4 = MyString(mstr2);

    std::cout << "mstr3 = "  << mstr3 << std::endl;
    MyString mstr5 = std::move(MyString("mstr5"));
    //move constructor should be here::
    MyString mstr6 = mstr4 + mstr5;
    std::cout << "mstr2 = "  << mstr2 << ",mstr4=" << mstr4
        << ",mstr5=" << mstr5 << std::endl;

    MyString mstr7 = std::move(mstr2+mstr4);

    std::cout << "mstr6 = "  << mstr6 << std::endl;
    std::cout << "mstr2 = "  << mstr2 << ",mstr4=" << mstr4 << std::endl;
    std::cout << "mstr7(moved) = " << mstr7 << std::endl;

    return 0;
}
