#ifndef __TEMPL_SUMM_HPP__
#  define __TEMPL_SUMM_HPP__

#include <iostream>
/**
 * printing all values inside container
 * * all that have "<<" implementation
 * 1st impl : with "auto" iterator
 */
template <typename T>
void print_all(const T& cont)
{
    for (auto it = cont.cbegin(); it != cont.cend(); ++it)
        std::cout << *it << " ";
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
    for (auto it = cont.cbegin(); it != cont.cend(); ++it)
        result += *it;
    return result;

}

#endif // __TEMPL_SUMM_HPP__
