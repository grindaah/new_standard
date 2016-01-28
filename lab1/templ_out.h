//pragma once
#ifndef __TEMPL_OUT__
#  define __TEMPL_OUT__

#include <iostream>
#include <map>
#include <string>
/**
* printing all values inside container
* * all that have "<<" implementation
* 1st impl : with "auto" iterator
*/
template <typename T>
void print_all(const T& cont)
{
	for (auto it = std::cbegin(cont); it != std::cend(cont); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

std::string operator -(std::string& st)
{
	std::string result(st);
	for (auto& c : result)
	{
		if (isalpha(c))
		{
			if (islower(c))
				c = toupper(c);
			else
				c = tolower(c);
		}
	}
	return result;
}

template <typename T>
void negate_all(T& cont)
{
	for (auto it = std::begin(cont); it != std::end(cont); ++it)
		*it = -*it;
	//for (auto& it : cont)
		
}

//TODO: template ostream << for pair with containers
/*ostream& operator << (ostream& os, std::pair <char, std::set<std::string> > set_strings)
{
	os << set_strings.first << ":" ;
	for (auto it : set_strings.second)
		os << it << ", ";
	return os;

}*/

#endif
