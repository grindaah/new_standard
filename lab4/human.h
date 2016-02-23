#ifndef __HUMAN__H__
#  define __HUMAN__H__

#include <memory>


const std::string default_name = "Default Name";

class human
{
    typedef std::shared_ptr<human> human_ptr;
    typedef std::weak_ptr<human> human_weak_ptr;

    std::string name;
    bool alive;
    bool male;

    int printer_depth;

    std::pair<human_weak_ptr, human_weak_ptr> parents;
    std::vector<human_weak_ptr> children;

    human() {}
public:

    human (const human& hmn)
    {
        std::cout << "cloning not allowed" << std::endl;
        name = hmn.name;
    }

    human operator = (human&& hmn)
    {
        return human (hmn);
    }

    human (human&& hmn) = default;

    human(std::string nm, bool ml = true)
    {
        name = nm;
        male = ml;
    }

    ///\note which ptr to use?
    void set_parents(human_weak_ptr p1, human_weak_ptr p2)
    {
        parents.first = p1;
        parents.second = p2;
    }

    static human_ptr child(human_ptr h1
            , human_ptr h2
            , std::string nm
            , bool male = true)
    {
        auto new_human = std::make_shared<human>(nm, male);
        human_weak_ptr new_human_ref = new_human;
        h1->add_child(new_human_ref);
        h2->add_child(new_human_ref);
        new_human->set_parents(h1,h2);
        return new_human;
    }

    std::string get_name()
    {
        return name;
    }

    std::string get_sex()
    {
        return male ? std::string("male") : std::string("female");
    }

    void add_child(human_weak_ptr chld)
    {
        children.push_back(chld);
    }

    ///get closest children
    human_ptr next()
    {}

    ///\TODO store the initial value of depth to calc the shift
    void print_tree(std::ostream& os, int max_depth = 15)
    {
        if (max_depth > 0)
        {
            os << "Name: " <<  name 
                << ", children: " << children.size() << std::endl;
            if (parents.first.lock())
            {
                std::string shift = std::string(" ",15 - max_depth);
                os << shift << "Parent 1: ";
                parents.first.lock()->print_tree(os, max_depth-1);
            }
            if (parents.second.lock())
            {
                std::string shift = std::string(" ",15 - max_depth);
                os << shift << "Parent 2: ";
                parents.second.lock()->print_tree(os, max_depth-1);
            }
        }
        else
            os << "max depth reached, call print tree with increased max_depth";
    }
};

std::ostream& operator << (std::ostream& os, std::shared_ptr<human> hmn)
{
    return os << "Name:" << hmn->get_name() << ", sex:" << hmn->get_sex()
        << ", live counters:" << hmn.use_count()
        << std::endl;
}

#endif
