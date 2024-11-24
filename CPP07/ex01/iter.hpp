#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename RT>

void iter(T *arr, size_t len, RT func)
{
    for (size_t i = 0; i < len; i++)
    {
        func(arr[i]);
    }
}

#endif