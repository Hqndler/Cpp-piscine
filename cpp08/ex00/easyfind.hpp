#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

template<typename T>
typename T::iterator easyfind(T &c, int value){
	return std::find(c.begin(), c.end(), value);
}

#endif