#pragma once

#include <iostream>
#include <map>

class A
{
public:
	A(const int& i) : m_int(i)
	{}
	int m_int = 0;
};

//===
template <typename T>
class MyCalc
{
	std::map<char, std::function<T(const T&,const T&)> > func_map;
	MyCalc(std::initializer_list lst) : func_map(lst)
		{
			//func_map.
		}

	/// {'+', []
	///  '%', std::bind
	///  '...'

	///pair ???
	/// T& operator[] (char a, val1, val2)
	///and this will give me function which awaits two const T& from the latter inp
	/*T operator+ (const T& val)
	{
		return func_map.['+'].second;
	}

	T operator- (const T& val)
	{
		return func_map.find('-').second;
	}*/
};


std::ostream& operator<<(std::ostream& os, const A& a)
{
	return os << a.m_int;
}

template <typename T>
void MyPrint(const T& para)
{
	std::cout << para << " ";
}

template  <typename T, typename ...Params>
void MyPrint(const T& para, const Params... params)
{
	std::cout << para << " ";
	MyPrint(params...);
}