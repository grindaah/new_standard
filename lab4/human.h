#ifndef __HUMAN__H__
#  define __HUMAN__H__

#include <shared_ptr>


class human
{
    typedef std::shared_ptr<human> human_ptr;
    typedef std::weak_ptr<human> human_weak_ptr;

    std::pair<human_weak_ptr, human_weak_ptr> parents;

    std::vector<human_weak_ptr> children;

    human(){}
public:

    human (const human& hmn)
    {
        std::cout << "cloning not allowed" << std::endl;
    }

    human operator = (human&& hmn)
    {
        return human (hmn);
    }

    human (human&& hmn) default;


    human(std::string nm, bool male = true)
    {
        name = nm;
        alive = al;
    }

    std::string name;
    bool alive;
    bool male;

    ///\note which ptr to use?
    void set_parents(human_weak_ptr p1, human_weak_ptr p2)
    {
        parents.first = p1;
        parents.second = p2;
    }

    static human child(human_ptr h1, human_ptr h2, std::string nm, bool male = true)
    {
        human_weak_ptr new_human = human_weak_ptr(new human(nm, male));
        h1.add_child(new_human);
        h2.add_child(new_human);
        ///parents as weak ptr?
        new_human.set_parents(h1,h2);
        return new_human;
    }

    static human child(const human& h1, const human& h2, std::string nm, bool male = true)
    {
        human_weak_ptr new_human = human_weak_ptr(new human(nm, male));
        h1.add_child(new_human);
        h2.add_child(new_human);
        new_human
        return 
    }

    void add_child(human_weak_ptr chld)
    {
        children.push_back(chld);
    }
    ///get closest children
    human_ptr next()
    {}
};


