//pragma once
#ifndef __TEMPL_OUT__
#  define __TEMPL_OUT__

#include <iostream>
#include <map>
#include <string>

#include "iterator_add.hpp"

/**
* printing all values inside container
* * all that have "<<" implementation
* 1st impl : with "auto" iterator
*/
template <typename T>
void print_all(const T& cont)
{
    for (auto it = std::cbegin(cont); it != std::cend(cont); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}


template< class C >
auto my_begin( C& c ) -> decltype(c.begin())
{
    return c.begin();
}

template< class T, std::size_t N >
T* my_begin( T (&array)[N] )
{
    return &array[0];
}

template< class C >
auto my_end( C& c ) -> decltype(c.end())
{
    return c.end();
}

template< class T, std::size_t N >
T* my_end( T (&array)[N] )
{
    return &array[N];
}

template< class C >
auto begin( const C& c ) -> decltype(c.begin());


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
    for (auto it = std::begin(cont); it != std::end(cont); ++it)
        *it = -*it;
    //for (auto& it : cont)
        
}

template <typename T>
ostream& operator << (ostream& os, const T& cont)
{

    std::cout << "Printing from container, type: " << typeinfo(cont).name() << std::endl;
    for (auto it = cont.cbegin(); it != cont.cend(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

}

//TODO: template ostream << for pair with containers
/*ostream& operator << (ostream& os, std::pair <char, std::set<std::string> > set_strings)
{
    os << set_strings.first << ":" ;
    for (auto it : set_strings.second)
        os << it << ", ";
    return os;

}*/

#endif
