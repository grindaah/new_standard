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
 * printing all values inside container
 * * all that have "<<" implementation
 * impl : with array support
 */
template <typename T>
void print_all_array(const T& cont)
{
    ///where ARE CBEGIN??
    //for (auto it = std::cbegin(cont); it != std::cend(cont); ++it)
    //    std::cout << *it << " ";
    std::cout << std::endl;
}

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
