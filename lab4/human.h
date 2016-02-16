#ifndef __HUMAN__H__
#  define __HUMAN__H__

class human
{
    typedef std::shared_ptr<human> human_ptr;
    typedef std::weak_ptr<human> human_weak_ptr;

    std::string name;
    bool alive;
    bool male;

    std::pair<human_ptr, human_ptr> parents;

    std::vector<human_weak_ptr> children;

};

operator + 
