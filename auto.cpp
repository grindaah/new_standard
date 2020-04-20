#include <stdio.h>
#include <iostream>
#include <typeinfo>
using namespace std;

double f() {return 0;}
int main()
{
	int count = 1;
	int& countRef = count;
	auto myAuto = countRef;
	countRef = 2;
	cout << count << endl; // 2
	myAuto = 3;
	cout << count <<endl; // 2

	auto x = "qwerty";
	cout << typeid(x).name() << endl; // PKc
	// c++filt -t PKc
	// char const*

	int a = 1, b = 2;
	auto y = a/b;
	cout << typeid(y).name() << endl; // int

	auto res = f();
	cout << typeid(res).name() << endl; // int

	auto p1 = new auto('a');
	cout << typeid(p1).name() << endl; // char*

	auto* p2 = new int[10];
	cout << typeid(p2).name() << endl; // int*

	auto z = 1, *p = &z;
	cout << typeid(z).name() << endl; // int
	cout << typeid(p).name() << endl; // int*

	auto c = {1,2,3,4,5}; 
	cout << typeid(c).name() << endl; // std::initializer_list<int>

	return 0;
}

