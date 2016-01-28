#ifndef __TEMPL_SUMMII_HPP__
#  define __TEMPL_SUMMII_HPP__

#include <iostream>
/**
 * printing all values inside container
 * * all that have "<<" implementation
 * 1st impl : with "auto" iterator
 */
template <typename T>
void print_all(const T& cont)
{
    for (const auto& it: cont)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}


/**
 * 2nd impl: with for-based-loop
 *
 */


template <typename T>
typename T::value_type summ(const T& cont)
{
    //user type will call constructor, POD will be initialized
    typename T::value_type result = {};
    for (const auto& it: cont)
    {
        result += it;
    }

    return result;

}

#endif // __TEMPL_SUMMII_HPP__
