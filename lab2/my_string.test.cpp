#include "my_string.h"

int main()
{
    ///default constructor
    MyString mstr1();
    ///char* constructor
    MyString mstr2("mstr2");
    ///Copy constructor
    MyString mstr3(mstr2);
    ///Operator = (+Copy constructor
    MyString mstr4 = MyString(mstr2);

    MyString mstr5 = std::move(MyString("mstr5"));
    
    MyString mstr6 = mstr4 + mstr5;

    std::cout << "mstr6 = "  << mstr6;

    return 0;

}
