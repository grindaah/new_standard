#include <vector>
#include <set>

#include <algorithm>


template <class T, class Compare = std::less<T> >
class unique_vector
{
    typedef typename std::vector<T>::iterator iter;
    typedef typename std::vector<T>::iterator citer;
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

    ///TODO probably this overload can be an template function
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

    iter get_iter(size_t index)
    {
        iter it = V.begin();
        std::advance(it, index);
        return it;
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
                , iter it
                )
        {
            std::vector<T> insertion(first, last);
            remove_duplicates(insertion);
            V.insert(it, insertion.begin(), insertion.end());
            remove_duplicates();
        }


    void erase(iter pos)
    {
        V.erase(pos);
    }

    void erase(iter first, iter last)
    {
        V.erase(first, last);
    }

    void erase(std::initializer_list<T> lst)
    {
         //std::vector<T> v = std::vector<T>(lst);
         //remove_duplicates(v);
         std::set<T> st_vals(lst);
         auto new_end = std::remove_if(V.begin(), V.end(), [&st_vals](const T& val)
                 {
                      return st_vals.find(val) != st_vals.end();
                 }
         );
         V.shrink_to_fit();

    }

    void find(const T& t) const
    {
        auto i = std::lower_bound(begin(), end(), t, cmp);
        //return i == end() || cmp(t, *i) ? end() : i;
    }
};
