#include <vector>
#include <set>

#include <algorithm>


template <class T, class Compare = std::less<T> >
class unique_vector
{
    std::vector<T> V;

    ///order matters (!)
    void remove_duplicates()
    {
        std::set<T> st_vals;
        std::vector<T> res;
        std::copy_if(V.begin(), V.end(), std::back_inserter(res), [&st_vals]
                (const T&val)
                {
                    return st_vals.insert(val).second;
                }
        );
        V.swap(res);
    }

    void remove_duplicates(std::vector<T>& vec)
    {
        std::set<T> st_vals;
        std::vector<T> res;
        std::copy_if(vec.begin(), vec.end(), std::back_inserter(res), [&st_vals]
                (const T&val)
                {
                    return st_vals.insert(val).second;
                }
        );
        vec.swap(res);
    }

public:
    Compare cmp;

    auto begin()->decltype(V.begin())
      { return V.begin(); }
    auto end()->decltype(V.end())
      { return V.end(); }
    auto cbegin()->decltype(V.cbegin()) const
        { return V.begin(); }
    auto cend()->decltype(V.cend()) const
        { return V.end(); }

    auto size()->decltype(V.size()) const
    { return V.size(); }

    ///we can declare operator[] to provide iterator for insertion
    ///or just leave this behavior as for native vector
    T operator[](size_t index) const
    {
        return V[index];
    }

    typename std::vector<T>::iterator get_iter(size_t index)
    {
        typename std::vector<T>::iterator iter = V.begin();
        std::advance(iter, index);
        return iter;
    }


    unique_vector(const Compare& c = Compare())
        : V(), cmp(c)
    {}

    ///TODO transform with binOP?
    template <class InputIterator>
        unique_vector(InputIterator first
                , InputIterator last
                , const Compare& c = Compare()
                ) : V(first, last), cmp(c)
        {
            remove_duplicates();
        }


    template <class InputIterator>
        void insert_into(InputIterator first
                , InputIterator last
                , typename std::vector<T>::iterator it
                )
        {
            std::vector<T> insertion(first, last);
            remove_duplicates(insertion);
            V.insert(it, insertion.begin(), insertion.end());

        }


    void insert(const T& t)
    {
        auto i = std::lower_bound(begin(), end(), t, cmp);
        if (i == end() || cmp(t, *i))
            V.insert(i, t);
        return;
    }

    void find(const T& t) const
    {
        auto i = std::lower_bound(begin(), end(), t, cmp);
        //return i == end() || cmp(t, *i) ? end() : i;
    }
};
