#include "sorted_vector.hpp"

#include <string>
#include <vector>
#include <set>

#include <iostream>

int main()
{
    std::set<std::string> s1 = {"an", "doctor", "a", "day", "keeps", "those", "apples", "away"};

    std::vector <int> v1 {1,4,6,5,1};

    std::vector <double> v2 {1.0, 2.2, 3.3, 0.0, 600, 50000.2};


    sorted_vector <std::string> sv1(s1.begin(), s1.end());
    sorted_vector <int> sv2(v1.begin(), v1.end());
    sorted_vector <double> sv3(v2.begin(), v2.end());

    for (const auto& it : sv1)
        std::cout << it << " ";
    std::cout << std::endl;
    for (const auto& it : sv2)
        std::cout << it << " ";
    std::cout << std::endl;
    for (const auto& it : sv3)
        std::cout << it << " ";
    std::cout << std::endl;
    return 0;
}
