#pragma once

#ifndef __MYSTRING_H__
#  define __MYSTRING_H__

#include <string>
#include <iostream>
#include <string.h>

template<typename T>
class MyArray
{
    T* m_pStr;

    MyArray() = delete;
public:
    MyArray(const MyArray&);
    MyArray(MyArray&&);
    MyArray(std::initializer_list lst);
    virtual ~MyArray();

    void friend Swap(MyArray&, MyArray&);

    friend std::ostream& operator<<(std::ostream&, const MyArray&);

    MyArray& operator=(const MyArray&);
    MyArray& operator=(MyArray&&);
    T operator[](size_t);
    MyArray operator+(const MyArray& rhv);

private:
    //void Construct(const char*);
};


#endif



