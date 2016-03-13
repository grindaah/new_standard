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
    std::cout << "Destructor calld" << std::endl;
    delete[] m_pStr;
}

MyString& MyString::operator=(const MyString& other)
{
    std::cout << "Copy opertor = called" << std::endl;
    if(this != &other && other.m_pStr != nullptr)
        Construct(other.m_pStr);
    return *this;
}

MyString::MyString(const MyString& other)
{
    std::cout << "Copy constructor called" << std::endl;
    if (other.m_pStr == m_pStr)
        return;
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
    std::cout << "Move constructor" << std::endl;
    m_pStr = other.m_pStr;
    other.m_pStr = nullptr;
}

///move operator=
MyString& MyString::operator=(MyString&& other)
{
    std::cout << "Move operator = called" << std::endl;
    delete m_pStr;
    m_pStr = other.m_pStr;
    other.m_pStr = nullptr;

    return *this;
}

ostream& operator<<(ostream& o, const MyString& str)
{
    return o << str.m_pStr;
}

MyString operator+(const MyString&lhv, const MyString& rhv)
{
    MyString result(lhv.m_pStr);
    std::cout << "operator + called" << std::endl;
    size_t count = strlen(rhv.m_pStr) + 1;
    void* end_it = result.m_pStr + strlen(result.m_pStr);
    ///possibly fastest way (std::copy as alternative)
    memcpy (end_it, rhv.m_pStr, count);
    return result;
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
