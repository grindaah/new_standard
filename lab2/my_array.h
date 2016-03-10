#pragma once

#ifndef __MYARRAY_H__
#  define __MYARRAY_H__

#include <string>
#include <iostream>
#include <initializer_list>
#include <utility>
#include <string.h>

const size_t res_copy_tail = 10;
const size_t reserve_mul = 5;
const size_t def_size = 1000;


template<typename T>
class MyArray
{
    T* m_ptr;

    size_t m_reserved;
    size_t m_size;

    void Construct(size_t sz)
    {
        for (size_t i = 0; i < m_size; ++i)
            m_ptr[i] = T();
    }

    void Deconstruct()
    {
        for (size_t i = 0; i < m_size; ++i)
            static_cast<T*>(&m_ptr[i])->~T();
    }

    void allocate(const size_t& sz)
    {
        size_t for_reserve = (sz > 1) ? sz * reserve_mul : def_size;
        m_ptr = static_cast<T *>(calloc(for_reserve, sizeof(T)));
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
        free(m_ptr);
        m_size = 0;
        m_reserved = 0;
    }

    void Realloc(size_t sz)
    {
        m_ptr = static_cast<T *> (realloc((m_ptr), sz * reserve_mul));
        m_reserved = sz * reserve_mul;
    }

    //MyArray() = delete;
    //void Construct(const char*);
public:
    MyArray(const std::initializer_list<T>& lst)
    {
        allocate(lst.size());
        size_t i = 0;
        ///move semantics doesn't work here,
        /// check http://open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4166.pdf
        for (auto it = lst.begin(); it != lst.end(); ++it)
            m_ptr[i++] = std::move(*it);
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
                memcpy(m_ptr, other.get_ptr(), sizeof(T)* new_size);
                //std::copy(m_ptr, other.get_ptr(), other.size());
            else
            {
                Realloc(other.size());
                memcpy(m_ptr, other.get_ptr(), sizeof(T)* new_size);
                //std::copy(m_ptr, other.get_ptr(), other.size());
            }
            m_size = new_size;
        }
    }

    MyArray& operator=(const MyArray& other)
    {
        std::cout << "Copy opertor= called" << std::endl;
        if(this != &other)
        {
            size_t new_size = other.size();
            Deconstruct();
            ///assuming that i allocate same size
            if (other.size() <= (m_reserved - sizeof(T)*res_copy_tail))
                memcpy(m_ptr, other.get_ptr(), sizeof(T)* new_size);
                //std::copy(m_ptr, other.get_ptr(), other.size());
            else
            {
                Realloc(other.size());
                memcpy(m_ptr, other.get_ptr(), sizeof(T)* new_size);
                //std::copy(m_ptr, other.get_ptr(), other.size());
            }
            m_size = new_size;
        }
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
            //m_reserved

            m_ptr = other.get_ptr();
            other.deactivate();
        }
    }


    virtual ~MyArray()
    {
        std::cout << "Destructor calld" << std::endl;
        Deconstruct();
        deallocate();
        //for (size_t i = 0; i < m_size; ++i)
        ///for... delete
        //delete m_ptr;
    }

    void push(const T& val)
    {
        if (m_reserved < (m_size + res_copy_tail))
            Realloc(m_size+1);
        *(m_ptr + m_size) = val;
        m_size++;
    }

    size_t size() const
    {
        return m_size;
    }

    T* get_ptr() const
    {
        return m_ptr;
    }

    size_t reserved() const
    {
        return m_reserved;
    }

    void deactivate()
    {
        m_ptr = nullptr;
    }


    T* operator[] (size_t idx) const
    {
        return &m_ptr[idx];
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



