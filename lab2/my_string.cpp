#include "my_string.h"

using namespace std;

MyString::MyString(const char* pStr)
{
    if(pStr)
        Construct(pStr);
    else
        m_pStr=nullptr;
}


MyString::~MyString(void)
{
    delete[] m_pStr;
}

MyString& MyString::operator=(const MyString& other)
{
    if(this != &other && other.m_pStr != nullptr)
    {
        size_t count = strlen(other.m_pStr) + 1;
        delete m_pStr;
        m_pStr = new char[count];
        memcpy (m_pStr, other.m_pStr, count);
    }
    return *this;
}

MyString::MyString(const MyString& other)
{
    if(other.m_pStr)
        Construct(other.m_pStr);
    else
        m_pStr = nullptr;
}

void MyString::Construct(const char* pStr)
{
    size_t count = strlen(pStr) + 1;
    m_pStr = new char[count];
    ///possibly fastest way (std::copy as alternative)
    memcpy (m_pStr, pStr, count);
}

///move construct
MyString::MyString(MyString&& other)
{
    m_pStr = other.m_pStr;
    other.m_pStr = nullptr;
}

///move operator=
MyString& MyString::operator=(MyString&& other)
{
    delete m_pStr;
    m_pStr = other.m_pStr;
    other.m_pStr = nullptr;

    return *this;
}

ostream& operator<<(ostream& o, const MyString& str)
{
    return o << str.m_pStr;
}

char MyString::operator[](size_t i)
{
    size_t len = strlen(m_pStr);
    if (i < len)
        return m_pStr[i];
    else
        return m_pStr[len];
        //we can throw exception here
        //throw std::out_of_range("Out of range!");
}
