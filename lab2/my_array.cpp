#include "my_array.h"


/*MyArray::MyArray(const char* pStr)
{
    if(pStr)
        Construct(pStr);
    else
        m_ptr=nullptr;
}

MyArray::~MyArray(void)
{

}

MyArray& MyArray::operator=(const MyArray& other)
{
    std::cout << "Copy opertor = called" << std::endl;
    if(this != &other && other.m_ptr != nullptr)
    {
        size_t count = strlen(other.m_ptr) + 1;
        delete m_ptr;
        m_ptr = new char[count];
        memcpy (m_ptr, other.m_ptr, count);
    }
    return *this;
}

MyArray::MyArray(const MyArray& other)
{
    std::cout << "Copy constructor called" << std::endl;
    if(other.m_ptr)
        Construct(other.m_ptr);
    else
        m_ptr = nullptr;
}


void MyArray::Construct(const char* pStr)
{
    size_t count = strlen(pStr) + 1;
    m_ptr = new char[count];
    ///possibly fastest way (std::copy as alternative)
    memcpy (m_ptr, pStr, count);
}

///move construct
MyArray::MyArray(MyArray&& other)
{
    std::cout << "Move constructor" << std::endl;
    m_ptr = other.m_ptr;
    other.m_ptr = nullptr;
}

///move operator=
MyArray& MyArray::operator=(MyArray&& other)
{
    std::cout << "Move operator = called" << std::endl;
    delete m_ptr;
    m_ptr = other.m_ptr;
    other.m_ptr = nullptr;

    return *this;
}

ostream& operator<<(ostream& o, const MyArray& str)
{
    return o << str.m_ptr;
}

MyArray MyArray:: operator+(const MyArray& rhv)
{
    std::cout << "operator + called" << std::endl;
    size_t count = strlen(rhv.m_ptr) + 1;
    void* end_it = m_ptr + strlen(m_ptr);
    ///possibly fastest way (std::copy as alternative)
    memcpy (end_it, rhv.m_ptr, count);
    return *this;

}

char MyArray::operator[](size_t i)
{
    size_t len = strlen(m_ptr);
    if (i < len)
        return m_ptr[i];
    else
        return m_ptr[len];
        //we can throw exception here
        //throw std::out_of_range("Out of range!");
}*/
