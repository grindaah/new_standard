#include "unique_vector.hpp"
#include "templ_out.h"

#include <string>
#include <vector>
#include <set>

#include <iostream>

int main()
{
    std::set<std::string> s1 = {"an", "doctor", "a", "day", "keeps", "those", "apples", "away"};

    std::vector <int> v1 {1, 4, 6, 5, 1, 1, 1, 1, 1, 11 };
    std::vector <int> v_ins {1111, 4, 6, 5, 1, 1, 1, 1, 1, 11 };

    std::vector <double> v2 {1.0, 2.2, 2.2, 3.3, 0.0, 600, 50000.2};
    //std::vector <int> v2_ins = static_cast<std::vector <int> >

    unique_vector <std::string> ss1(s1.begin(), s1.end());
    unique_vector <int> sv1(v1.begin(), v1.end());

    unique_vector <double> sv2(v2.begin(), v2.end()); //, std::greater<double>() );

    std::cout<< "ss1" << std::endl;
    for (const auto& it : ss1)
        std::cout << it << " ";
    std::cout << std::endl;
    std::cout<< "sv1" << std::endl;
    for (const auto& it : sv1)
        std::cout << it << " ";
    std::cout << std::endl;
    std::cout<< "sv2" << std::endl;
    for (const auto& it : sv2)
        std::cout << it << " ";
    std::cout << std::endl;

    std::cout << "====================" << std::endl;
    std::cout << "===Insertion========" << std::endl;

    std::set <std::string> v_ins_string = {"Here", "goes", "some", "more", "strings", "I", "will", "paste", "first", "five"};
    ss1.insert_into(v_ins_string.begin(), v_ins_string.find("some"), ss1.get_iter(4));

    std::cout<< "ss1" << std::endl;
    for (const auto& it : ss1)
        std::cout << it << " ";
    //sv2.insert_into(v_ins.begin(), v_ins.end(), sv2.get_iter(4));
    //for (const auto& it : sv2)
    //    std::cout << it << " ";
    //std::cout << std::endl;

    return 0;
}
