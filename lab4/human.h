#ifndef __HUMAN__H__
#  define __HUMAN__H__

class human
{
    typedef std::shared_ptr<human> human_ptr;
    typedef std::weak_ptr<human> human_weak_ptr;

    std::pair<human_ptr, human_ptr> parents;

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


    human(std::string nm, bool al = true)
    {
        name = nm;
        alive = al;
    }
    std::string name;
    bool alive;
    bool male;


    void add_child(human_weak_ptr chld)
    {
        children.push_back(chld);
    }
    ///get closest children
    human_ptr next()
    {}
};

