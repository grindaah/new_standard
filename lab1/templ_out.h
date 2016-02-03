//pragma once
#ifndef __TEMPL_OUT__
#  define __TEMPL_OUT__

#include <iostream>
#include <string>
#include <vector>

#include "../iterator_add.hpp"


/**
* printing all values inside container
* * all that have "<<" implementation
* 1st impl : with "auto" iterator
*/
template <typename T>
void print_all(const T& cont)
{
    for (auto it = my_begin(cont); it != my_end(cont); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

std::string operator- (std::string& st)
{
    std::string result(st);
    for (auto& c : result)
    {
        if (isalpha(c))
        {
            if (islower(c))
                c = toupper(c);
            else
                c = tolower(c);
        }
    }
    return result;
}

template <typename T>
void negate_all(T& cont)
{
    for (auto it = my_begin(cont); it != my_end(cont); ++it)
        *it = -*it;
}

template <typename T1, typename T2>
std::ostream& operator << (std::ostream& os, std::pair<T1, T2> pair)
{
    std::cout << "Printing from container, type: " << typeinfo(pair).name() << std::endl;
    //for (auto it = cont.cbegin(); it != cont.cend(); ++it)
    //    std::cout << *it << " ";
    //std::cout << std::endl;

}

//1st implementation - for_each
template <typename T1, typename T2>
std::vector<typename T1:: value_type> SumCont1(const T1& c1, const T2& c2)
{
    typedef std::vector<typename T1:: value_type> res_type;
    typedef typename std::vector<typename T1:: value_type>::iterator res_iter;
    res_type result = res_type(std::max(c1.size(), c2.size()));

    //size_t min_size = std::max(c1.size(), c2.size());
    typename T1:: const_iterator first1 = my_begin(c1);
    typename T2:: const_iterator first2 = my_begin(c2);
    ///since std c++11 for_each will implement move-semantics for function return statement
    ////                                                            std::vector<typename T1:: value_type>:: iterator it
    std::for_each(result.begin(), result.end(),[&first1, &first2, &c1, &c2] (res_type it) {
                if (first1 != c1.end())
                {
                    it += *first1;
                    ++first1;
                }
                if (first2 != c2.end())
                {
                    it += *first2;
                    ++first2;
                }
            }
    );
    return result;
}

//template <typename T1, typename T2>


///2nd implementation - construct from smaller container , transform with addition,
// then - move rest part via std;:copy
template <typename T1, typename T2>
auto SumCont2(const T1& c1, const T2& c2) -> std::vector <decltype( * (c1.begin()) + * (c2.begin()) ) >
{
    ///Check this neat typedef in TRT
    typedef typename std::vector <decltype( *(c1.begin()) + *(c2.begin()) )> res_type;
    typedef typename T1:: value_type type_cont1;
    typedef typename T2:: value_type type_cont2;

    /// choose max container for size of result
    res_type result = res_type( std::max(c1.size(), c2.size()) );

    std::transform(c1.begin(), c1.end(), c2.begin(), result.begin(), [](type_cont1 el1, type_cont2 el2 ) {
                return el1 + el2;
            }
    );

    return result;
}

/// TODO
//template <typename T1, typename T2>
//T1 operator+ (const T1& lhv, const T2& rhv)
//{
//    
//}

//TODO: template ostream << for pair with containers
// *** or for map ??
/*ostream& operator << (ostream& os, std::pair <char, std::set<std::string> > set_strings)
{
    os << set_strings.first << ":" ;
    for (auto it : set_strings.second)
        os << it << ", ";
    return os;

}*/

#endif
