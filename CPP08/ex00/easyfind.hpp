#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template <typename T>
int const &easyfind(T &container, int val)
{
    typename T::iterator it = std::find(container.begin(), container.end(), val);
    if (it == container.end())
    {
        throw std::out_of_range("Value Not Found");
    }
    return *it;
}
#endif