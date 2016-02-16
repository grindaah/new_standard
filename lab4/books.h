#pragma once

#ifndef __BOOK_H__
#  define __BOOK_H__

#include <iostream>
#include <string>
#include <tuple>

enum class Genre
{
    detective,
    romance,
    thriller,
    mystics,
    scifi,
    unspecified,
};

//constexpr Genre unspec = Genre::unspecified;
std::ostream& operator<< (std::ostream& os, std::tuple <std::string, std::string, int, Genre> tpl)
{
    return os << "auth: " << std::get<1>(tpl) << ", nm: " << std::get<0>(tpl)
        << ",year: " << std::get<2>(tpl);
}

class Book
{
    std::string name;
    std::string author;
    int year;
    Genre genre;

    Book() {};
        
public:
    std::string get_name() const
    {
        return name;
    }
    std::string get_author() const
    {
        return author;
    }
    int get_year() const
    {
        return year;
    }

    Book(const std::string& str)
    {
        name = str;
        genre = Genre::unspecified;
    }
bool operator< (const Book& rhv)
{
    if (name == rhv.get_name())
    {
        if (author == rhv.get_author())
            return year < rhv.get_year();
        else
            return author < rhv.get_author();
    }
    else
        return name < rhv.get_name();

}
};


#endif
