#pragma once

#ifndef __MYARRAY_H__
#  define __MYARRAY_H__

#include <string>
#include <iostream>
#include <string.h>
#include <initializer_list>
#include <utility>

const size_t res_copy_tail = 10;
const size_t reserve_mul = 5;


template<typename T>
class MyArray
{
    T* m_ptr;

    size_t m_reserved;
    size_t m_size;

    void Construct(T* p, size_t sz);
    void Deconstruct()
    {
        ///we can m_ptr[] and delete[]... hmmm
        for (size_t i = 0; i != m_size; ++i)
            delete m_ptr[i];
    }

    void allocate(const size_t& sz)
    {
        size_t for_reserve = sz * reserve_mul;
        m_ptr = static_cast<T *>(malloc(for_reserve));
        if(m_ptr)
        {
            m_reserved = for_reserve;
            m_size = sz;
        }
        else
            std::cerr << "Memory was not initialized";
    }

    void deallocate()
    {
        free(m_ptr, m_size);
        m_size = 0;
        m_reserved = 0;
    }

    void Realloc(size_t sz)
    {
        m_ptr = realloc(m_ptr, sz * 8);
        m_reserved = sz * 8;
    }

    //MyArray() = delete;
    //void Construct(const char*);
public:
    MyArray(const std::initializer_list<T>& lst)
    {
        allocate(lst.size());
        for (auto it : lst)
        {
            size_t i = std::distance(std::begin(lst), it);
            m_ptr[i] = std::move(it);
        }
    }

    MyArray(const MyArray& other)
    {
        std::cout << "Copy ctor called" << std::endl;
        if(this != &other)
        {
            size_t new_size = other.size();
            Deconstruct();
            ///assuming that i allocate same size
            if (other.size() <= (m_reserved - sizeof(T)*res_copy_tail))
                std::copy(m_ptr, other.get_ptr(), other.size());
            else
            {
                //deallocate();
                //allocate(other.size());
                Realloc(other.size());
                std::copy(m_ptr, other.get_ptr(), other.size());
            }
        }
    }

    MyArray& operator=(const MyArray& other)
    {
        /*std::cout << "Copy opertor= called" << std::endl;
        if(this != &other)
        {
            size_t new_size = other.size();
            Deconstruct();
            ///assuming that i allocate same size
            if (other.size() <= (m_reserved - sizeof(T)*res_copy_tail))
                std::copy(m_ptr, other.get_ptr(), other.size());
            else
            {
                deallocate();
                allocate(other.size());
                std::copy(m_ptr, other.get_ptr(), other.size());
            }
        }*/

        //MyArray(std::forward<T>(rhv));
        //return MyArray(rhv);
    }

    MyArray& arr_create(T&& new_ar)
    {
        return MyArray(std::forward<T>(new_ar));
    }

    MyArray(MyArray&& other)
    {
        if(this != &other)
        {
            m_size = other.size();
            Deconstruct();

            ///\note only one element moved
            if (other.size() <= (m_reserved - sizeof(T)*res_copy_tail))
                m_ptr = std::move(other.get_ptr());
            else
            {
                deallocate();
                allocate(other.size());
                m_ptr = std::move(other.get_ptr());
            }
        }
    }


    virtual ~MyArray()
    {
        std::cout << "Destructor calld" << std::endl;
        ///for... delete
        delete m_ptr;
    }

    void push(const T& val)
    {
        if (m_reserved < (m_size+10))
            *(m_ptr + m_size) = val;
        m_size++;
    }

    size_t size()
    {
        return m_size;
    }

    T* get_ptr()
    {
        return m_ptr;
    }

    T* operator[] (size_t idx) const
    {
        return (m_ptr + idx);
    }

    friend std::ostream& operator<<(std::ostream& os, const MyArray& ar)
    {
        os << "Array sz:" << ar.m_size << ", reserved:" << ar.m_reserved
              << std::endl;
        for (int i = 0; i < ar.m_size; ++i)
            os << *ar[i] << ", ";
        os << std::endl;
        return os;
    }

    /*void friend Swap (MyArray&, MyArray&);

    friend std::ostream& operator<<(std::ostream&, const MyArray&);


    MyArray& operator=(MyArray&&);
    T operator[](size_t);
    MyArray operator+(const MyArray& rhv);*/


};


#endif



