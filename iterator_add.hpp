#ifndef __ITERATOR_ADD_HPP__
#  define __ITERATOR_ADD_HPP__

#include <iterator>

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

#endif
