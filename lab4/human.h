#ifndef __HUMAN__H__
#  define __HUMAN__H__

#include <shared_ptr>


class Human
{
    typedef std::shared_ptr<Human> human_ptr;
    typedef std::weak_ptr<Human> human_weak_ptr;

    std::string name;
    bool alive;
    bool male;

    std::pair<human_ptr, human_ptr> parents;

    std::vector<human_weak_ptr> children;


};


