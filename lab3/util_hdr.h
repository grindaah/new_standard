#pragma once

#include <iostream>
#include <string>


#include <limits.h>

static const std::string myname = "Marina";

/*void operator"" _name(const char* str, size_t n)
{
    std::cout << str << myname <<std::endl ;
}*/

constexpr unsigned int factr(unsigned int n)
{
    return n > 2 ? n * factr(n - 1) : n;
}

std::string operator "" _name(const char* str, size_t)
{
   std::string res = std::string(str) + myname;
   return res;
}

constexpr size_t fun(const char* remain, size_t res)
{
    return *remain == '\0' ? res : fun(remain + 1, *remain == '1' ? ((res << 1) + 1) : (res << 1));
}

constexpr size_t idx(const char* str)
{
    return str ? idx(str++) : 0;
}

size_t binsize(unsigned long long num)
{
    unsigned long long mask = USHRT_MAX;
    mask = mask << (6 * CHAR_BIT);
    std::cout << mask << std::endl;
    for (int i = 4; i; i--)

    {
        std::cout << ((mask & num) >> ((i-1)*CHAR_BIT*2 )) ;
        if ( ( (mask & num) >> ((i-1)*CHAR_BIT*2 )) != USHRT_MAX )
            return i;
        else
            mask = mask >> (2*CHAR_BIT);

    }
}

///toBinStr variation1
std::string operator "" _toBinStr(unsigned long long num)
{
    unsigned long long mask = 1;
    std::string result = std::string();
    while (mask <= num)
    {
        (mask & num) == mask ? result.insert(result.begin(), '1') : result.insert(result.begin(), '0');
        mask = mask << 1;
    }
    //result.insert(result.begin(), "0b");
    return result;
}

//constexpr size_t ff(size_t res, const char* str)
constexpr size_t operator "" _b(const char* str)
{
    return fun(str, 0);
}

/*uint64_t operator "" _b(const char* str, size_t)
{
    std::string s(str);
    size_t sz = s.length();
    uint64_t res = 0;
    char c = 0;
    for (char c : s)

    for (size_t v = sz - 1; v > 0; v--, c = str[v - 1])
    {
        char c = str[v];
        if (c == '1')
            res += (1 << (sz - v) );
    }        
    
    return res;
}*/

/*void* operator new (size_t sz, std::string * ptr)
{
    return std::unique_ptr<std::string>(ptr);
}*/

template <typename T>
class ConstrValue
{
    const T m_t;

public:
    constexpr ConstrValue(const T& t) : m_t(t)
    {

    }
    constexpr T get() const
    {
        return m_t;
    }

};
