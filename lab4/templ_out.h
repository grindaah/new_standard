#pragma once

#include <iostream>
#include <map>


///\note for MyPrint template
class A
{
public:
    A(const int& i) : m_int(i)
    {}
    int m_int = 0;
};


template <typename T>
T my_plus(const T& a, const T& b)
{
    return a + b;
}

template <typename T>
T division_res(const T& a, const T& b)
{
    return a % b;
}

template <typename T>
struct my_multiply
{
    typedef T result_type;

    my_multiply()
    {}

    T operator() (const T& a, const T& b)
    {
        return a*b;
    }
};

//===
template <typename T>
class MyCalc
{
    public:
        typedef std::function<T(const T&, const T&)> func_type;
        typedef std::map<char, func_type> func_map_type;

        func_map_type func_map;
        MyCalc()
        {}

        ~MyCalc()
        {}

        MyCalc(std::initializer_list<T> lst) : func_map(lst)
        {
            //func_map.
        }

        void operator() (char a, func_type f)
        {
            func_map.insert(std::make_pair(a, f));
        }

        void insert  (char a, func_type f)
        {
            func_map.insert(std::make_pair(a, f));
        }

        func_type operator[] (char a)
        {
            return func_map[a];
        }
    ///and this will give me function which awaits two const T& from the latter inp
    /*T operator+ (const T& val)
    {
        return func_map.['+'].second;
    }

    T operator- (const T& val)
    {
        return func_map.find('-').second;
    }*/
};


std::ostream& operator<<(std::ostream& os, const A& a)
{
    return os << a.m_int;
}

template <typename T>
void MyPrint(const T& para)
{
    std::cout << para << std::endl;
}

template  <typename T, typename ...Params>
void MyPrint(const T& para, const Params... params)
{
    std::cout << para << " ";
    MyPrint(params...);
}

