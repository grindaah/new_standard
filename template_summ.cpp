#include <iostream>

//include <veсtor>
#include <list>
#include <map>

#include "templ_summ.hpp"

class userClass
{

public:
    static int counter;
    int field_counter;
    userClass()
    {
        counter++;
        std::cout << "constructor called, counter=" << counter <<  std::endl;
        //field_counter = ++counter;
    }


};

int userClass::counter = 0;

std::ostream& operator << (std::ostream& os, const userClass& uc)
{
    return os << userClass::counter;
}

int main()
{

    //std::vector<int> v1 = {1,2,3,4,5,6};
    std::list<int> l1 = {1,2,3,4,5,6};
    std::list<userClass> uc1(6);

    //print_all(v1);
    print_all(l1);
    print_all(uc1);

    std::cout //<< summ(v1) << " "
        << summ(l1) << std::endl;

return 0;
}
