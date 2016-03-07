#ifndef __WRAP_ANY__H__
#  define __WRAP_ANY__H__

#include <utility>
#include <sstream>
#include <iostream>

class BaseSerial
{
protected:
    std::string m_str;
public:
    std::string get_str() const
    {
        return m_str;
    }

    friend BaseSerial operator+ (const BaseSerial& lhv, const BaseSerial& rhv)
    {
        BaseSerial result;
        result.m_str = lhv.m_str + rhv.m_str;
        return result;
    }

    BaseSerial& operator+= (const BaseSerial& rhv)
    {
        m_str += rhv.get_str();
        return *this;
    }

    ///Letting the constructors be defaults
};

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
    ///TODO unique_ptr to make it manage deleting itself
    BaseSerial* m_p;
public:

    BaseSerial* const get_mp() const
    {
        return m_p;
    }

    template<typename T>
    WrapAny(const T& t)
    {
        m_p = new Any<T>(t);
    }

    /*template<typename T>
    WrapAny(const Any<T>& a)
    {
        m_p = a;
    }*/

    friend WrapAny operator+ (const WrapAny& lhv, const WrapAny& rhv)
    {
        WrapAny result(std::string(""));
        *result.m_p = *lhv.m_p + *rhv.m_p;

        return result;
    }

    WrapAny& operator +=(const WrapAny& rhv)
    {
        *m_p += *rhv.get_mp();
        return *this;
    }

    friend std::ostream& operator << (std::ostream& os, const WrapAny& w)
    {
        return os << w.m_p->get_str();
    }
};



#endif

