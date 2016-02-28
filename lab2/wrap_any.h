#ifndef __WRAP_ANY__H__
#  define __WRAP_ANY__H__

#include <utility>
#include <sstream>
#include <iostream>

class BaseSerial
{
public:
    std::string m_str;

    friend BaseSerial operator+ (const BaseSerial& lhv, const BaseSerial& rhv)
    {
        BaseSerial result;
        result.m_str = lhv.m_str + rhv.m_str;
        return result;
    }

    ///Letting the constructors be defaults

//    friend std::ostream& os(std::ostream& os, const BaseSerial& bs);
//    friend std::ostream& os(std::ostream& os, BaseSerial* bs);
};

/*std::ostream& os(std::ostream& os, BaseSerial* bs)
{
    return os << bs->m_str;
}

std::ostream& os(std::ostream& os, const BaseSerial& bs)
{
    return os << bs.m_str;
}*/

template<typename T> class Any : public BaseSerial
{
public:
    Any(const T& t = T())
    {
        std::stringstream ss;
        ss << t;
        m_str = ss.str();
    }
};


class WrapAny
{
    BaseSerial* m_p;
public:

    template<typename T>
    WrapAny(const T& t)
    {
        m_p = new Any<T>(t);
    }

    template<typename T>
    WrapAny(const Any<T>& a)
    {
        m_p = a;
    }

    //template <typename T1, typename T2>
    friend WrapAny operator+ (const WrapAny& lhv, const WrapAny& rhv)
    {
        WrapAny result(lhv);
        *result.m_p = *result.m_p+*rhv.m_p;

        return result;
    }

    friend std::ostream& operator << (std::ostream& os, const WrapAny& w)
    {
        return os << w.m_p->m_str;
    }
};



#endif

