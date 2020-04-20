#include <vector>
#include <algorithm>

template <class T, class Compare = std::less<T> >
class sorted_vector
{
//    using std::vector;
//    using std::lower_bound;
    std::vector<T> V;
public:
    Compare cmp;

    typedef typename std::vector<T>::iterator iterator;
    typedef typename std::vector<T>::const_iterator const_iterator;
    iterator begin()  { return V.begin(); }
    iterator end()  { return V.end(); }
    const_iterator begin() const { return V.begin(); }
    const_iterator end()   const { return V.end(); }

    sorted_vector(const Compare& c = Compare())
        : V(), cmp(c)
    {}
    template <class InputIterator>
        sorted_vector(InputIterator first, InputIterator last,
            const Compare& c = Compare()) : V(first, last), cmp(c)
        {
            std::sort(begin(), end(), cmp);
        }
    iterator insert(const T& t)
    {
        iterator i = std::lower_bound(begin(), end(), t, cmp);
        if (i == end() || cmp(t, *i))
            V.insert(i, t);
        return i;
    }
    const_iterator find(const T& t) const
    {
        const_iterator i = std::lower_bound(begin(), end(), t, cmp);
        return i == end() || cmp(t, *i) ? end() : i;
    }
};
