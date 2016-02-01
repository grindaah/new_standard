#include <vector>
#include <algorithm>

template <class T, class Compare = std::less<T> >
class unique_vector
{
    std::vector<T> V;
public:
    Compare cmp;

    auto begin() { return V.begin(); }
    auto end() { return V.end(); }
    auto begin() const
        { return V.begin(); }
    auto end() const
        { return V.end(); }

    auto size() const
    { return V.size(); }

    ///we can declare operator[] to provide iterator for insertion
    ///or just leave this behavior as for native vector
    T operator[](size_t index) const
    {
        return V[index];
    }

    typename std::vector<T>::iterator get_iter(size_t index)
    {
        //if (index > V.size())
        //    return end();
        typename std::vector<T>::iterator iter = V.begin();
        std::advance(iter, index);
        return iter;
    }


    unique_vector(const Compare& c = Compare())
        : V(), cmp(c)
    {}

    template <class InputIterator>
        unique_vector(InputIterator first, InputIterator last,
            const Compare& c = Compare()) : V(first, last), cmp(c)
        {
            auto it = std::unique(V.begin(), V.end());
            V.resize( std::distance(V.begin(), it ) );
        }

    template <class InputIterator>
        void insert_into(InputIterator first
                , InputIterator last
                , InputIterator it//std::vector<T>::iterator it
                )
        {
            if (first!=last)
            {
                auto result(V);
                size_t dist = std::distance(begin(), it);

                result.reserve(V.size() + std::distance(first, last));
                ///there is no more back_inserter :(
                //std::copy(first, last, std::back_inserter(it) );
                result.insert(result.begin() + dist, first, last);
                std::unique(result.begin(), result.end(), cmp);
                V.swap(result);
            }
        }

    auto insert(const T& t)
    {
        auto i = std::lower_bound(begin(), end(), t, cmp);
        if (i == end() || cmp(t, *i))
            V.insert(i, t);
        return i;
    }

    auto find(const T& t) const
    {
        auto i = std::lower_bound(begin(), end(), t, cmp);
        return i == end() || cmp(t, *i) ? end() : i;
    }
};
