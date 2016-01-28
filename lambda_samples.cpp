#include <iostream>

#include <vector>
#include <algorithm>


#include "templ_summ.hpp"

//void f_add(double& y)
//{
//    
//}

int main()
{
    //simpler lambda
    [](int x)
        {std::cout << "x multiplier, " << x*x; };

    //lambda adding 2.0 to arg
    auto add = [](double& y)
        {return y += 2.02; };

    std::vector<double> v1(10, 2.0);
    
    std::for_each(v1.begin(), v1.begin() + 5, add);

    print_all(v1);


    ///copy vs reference sample
    int ar[] = {5, -1, 4, -7, 3};
    std::for_each(ar, ar + sizeof(ar)/sizeof(int),
            [](int& x)
              { x++; }
    );

    //print_all(ar);
    for (const auto& x : ar)
    {   std::cout<< x << " "; };


    return 0;
}
