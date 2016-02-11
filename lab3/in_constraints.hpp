#ifndef __IN_CONSTRAINTS_HPP__
#  define __IN_CONSTRAINTS_HPP__

template <typename T>
class InConstraints
{
    T m_min;
    T m_max;
    public:
    constexpr InConstraints(T&& min, T&& max) : m_min(min)
                                                , m_max(max)
    {}
    constexpr bool check(const T& val)
    {
        return val >= m_min && val <= m_max;
    }

    constexpr T get(const T& val)
    {
        return val < m_min ? m_min : val > m_max ? m_max : val;
    }


};


#endif
