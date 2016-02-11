#pragma once

#ifndef __MYSTRING_H__
#  define __MYSTRING_H__

#include <string>
#include <iostream>
#include <string.h>


class MyString
{
    char* m_pStr;
public:
    MyString(const char* pStr=nullptr);
    MyString(const MyString&); 
    MyString(MyString&&);
    ~MyString(void);

    MyString& operator=(const MyString&);
    MyString& operator=(MyString&&);
    char operator[](size_t);

    void friend Swap(MyString&, MyString&);

    friend std::ostream& operator<<(std::ostream&, const MyString&);

private:
    void Construct(const char*);
};


#endif



